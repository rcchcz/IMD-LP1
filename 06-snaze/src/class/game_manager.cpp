/*!
 * @file game_manager.cpp
 *
 * Implementation of the game manager class.
 */

#include "game_manager.h"

//======================[ MAIN METHODS ] ======================//

bool GameManager::validate( int argc, char * argv[] )
{ 
    if(argc == 1){
        cout << "Usage: snaze [<options>] <input_level_file>\n";
        cout << "   Game simulation options:\n";
        cout << "   --help               Print this help text.\n";
        cout << "   --fps <num>          Number of frames (board) presented per second. Default = 24.\n";
        cout << "   --lives <num>        Number of lives the snake shall have. Default = 5.\n";
        cout << "   --food <num>         Number of food pellets for the entire simulation. Default = 10.\n";
        cout << "   --playertype <type>  Type of snake intelligence: random, backtracking. Default = backtracking.\n";
        return false;
    }

    for(SK::count a = 0; a < 50; a++) { cout << "=";}
    cout <<"\n";
    cout << ">>>>>>>>> Welcome to the classic Snake Game <<<<<<<<<\n";
    cout << " copyright (C) 2021, Rita Cruz and Victor Vieira T.\n";
    for(SK::count a = 0; a < 50; a++) { cout << "-";}
    cout <<"\n";

    for(SK::count i = 1; i < (argc-2); i++) {
        if(strcmp(argv[i], "--fps") == 0) {
            i++;
            set_fps(atoi(argv[i]));
        } else if(strcmp(argv[i], "--lives") == 0) {
            i++;
             set_lives(atoi(argv[i]));
        } else if(strcmp(argv[i], "--food") == 0) {
            i++;
            set_foods(atoi(argv[i]));
        } else if(strcmp(argv[i], "--playertype") == 0) {
            i++;
            set_playertype(argv[i]);
        }
    }
    cout << ">>> Preparing to read inpt file \" "<< argv[argc-1]<<"\"...\n";
    
    if(!analyze_file(argv[argc-1]))
    { 
        cout << ">>> ERROR: something went wrong on reading the Input file.\n\n";
        return false;
    }
    
    return true;
}

bool GameManager::analyze_file(char *argv)
{ 
    string filename(argv), temp;

    cout << ">>> Processing data, please wait. \n";
    //Try to open the file
    ifstream input_file(filename);
    if(!input_file.is_open()) { return false; } 
    
    while(getline(input_file, temp)) {
        string intermediate;
        stringstream s_stream(temp);
        bool is_valid = true;
        bool spawn = false;
        Levels.resize(Levels.size()+1);
        getline(s_stream, intermediate, ' ');
        Levels[Levels.size() - 1].row = validate_row_collumn(intermediate);
        Levels[Levels.size() - 1].matrix.resize(Levels[Levels.size()-1].row);
        getline(s_stream, intermediate, ' ');
        Levels[Levels.size() - 1].collumn = validate_row_collumn(intermediate);

        for(SK::count i = 0; i < Levels[Levels.size() - 1].row; i++) {
            getline(input_file, temp);
            for(char& c : temp) {
                // Here add elements to the vector of White Spaces 
                if( c == ' ' || c == '*') {
                    SK::coord ws_f;
                    ws_f.x =  Levels[Levels.size()-1].matrix[i].size();
                    ws_f.y = i;
                    Levels[Levels.size()-1].Ws.push_back(ws_f);
                }
                if(c == '*') { 
                    spawn = true;
                    Levels[Levels.size()-1].spawn.y = i;
                    Levels[Levels.size()-1].spawn.x =  Levels[Levels.size()-1].matrix[i].size();
                    Levels[Levels.size()-1].matrix[i].push_back(' ');
                } else if(c == '.' ||  c == ' ') {
                    Levels[Levels.size()-1].matrix[i].push_back(c); 
                } else if(c == '#') {
                    Levels[Levels.size()-1].matrix[i].push_back('#');
                }else{
                    is_valid = false;     
                }
            }
        }

        // Delete invalid level
        if(is_valid == false || spawn == false) { Levels.pop_back(); }
    }

    if(Levels.size() == 0) {cout << ">>> Level not found. Closing game.\n"; }
    return true;
}

SK::Game_status GameManager::quit_game() { return status; }

void GameManager::update() {
    // Change level if all expected fruits have been eaten
    if(Levels[curr_lvl].eaten == foods) {
        
        for(SK::count i = 0; i < 50; i++) { cout << "_";}
        cout << "\n";
        cout << ">>> Completed level " << ++curr_lvl << "(of " << Levels.size() << ") successfully!\n";
    
        // End the game if passed all levels -- the player won the game
        if(curr_lvl == Levels.size()) { 
            status = SK::Game_status::WON;
            curr_lvl--;
            return;
        // There are still levels to play
        } else {
            m_snake.reset();
            cout << ">>> Press ENTER to start next level!\n";
            cin.get();
        }
    }
    
    // Spawn fruit
    if(Levels[curr_lvl].fruit.x == 0 &&  Levels[curr_lvl].fruit.y == 0) { Levels[curr_lvl].fruit_spawn(m_snake.body); }
    if(m_snake.body.size() == 0 ) {  
        m_snake.set_spawn(Levels[curr_lvl].spawn);
        num_path = 1;
        if(player_type == SK::Game_mode::BACKTRACKING) {  
            backtracking = true;
            move_smart();
        }
    }
    
    if(backtracking) { 
        // If any path was found, move a random direction
        if(paths.size() == 1) { 
            status = SK::Game_status::LOSE;
            backtracking = false; 
            move_rand();
        } else if(m_snake.advance(paths[num_path].dir, Levels[curr_lvl].fruit)) {
            score += combo * 20;
            combo++;
            Levels[curr_lvl].eaten++;
            Levels[curr_lvl].fruit_spawn(m_snake.body);
            move_smart(); 
            num_path = 0;        
        }
        num_path++;
    } else { move_rand(); }
    
    //There is no place to the snake go, loose one life
    if(lives > 0 && status == SK::Game_status::LOSE) {
        m_snake.reset();
        lives--;
        m_snake.set_spawn(Levels[curr_lvl].spawn);
        combo = 1;
        status = SK::Game_status::IN_PROGRESS;
        if(player_type == SK::Game_mode::BACKTRACKING) { 
            move_smart();
            num_path=1;
            backtracking = true; 
        }
    } 
} 

void GameManager::render() {
    // Header
    for(SK::count i = 0; i < 50; i++) { cout << "_"; }
    cout << "\n\n";
    cout << "Lives: ";
    for(int i = 0; i < lives; i++) { cout << "♥"; }
    cout << " | Score: " << score << " | Food eaten: " << Levels[curr_lvl].eaten << " of " << foods << "\n";
    // cout << "Game Mode: ";
    // if(backtracking) { cout << "BACKTRACKING\n";}
    //     else{cout << "RANDOM\n"; }
    for(SK::count i = 0; i < 50; i++) { cout << "_"; }
    cout << "\n\n";
    
    // Create image, with matrix, snake and fruit position
    image = Levels[curr_lvl].matrix;
    image[m_snake.body[0].y][m_snake.body[0].x] = m_snake.head_char();
    for(SK::count i = 1; i < m_snake.body.size(); i++) {
       image[m_snake.body[i].y][m_snake.body[i].x] = '*';
    }
    image[Levels[curr_lvl].fruit.y][Levels[curr_lvl].fruit.x] = 'O'; 
    
    // Print image
    for(SK::count j = 0; j < image.size(); j++) {
        for(SK::count k = 0; k < image[0].size(); k++) {
            if(image[j][k] == '.') { cout << ' '; }
            else if(image[j][k] == '#') { cout << "█"; }
            else if(image[j][k] == 'O') { cout << "☢"; }
            else { cout << image[j][k]; } 
        }
        cout << '\n'; 
    }
    cout << "\n";  
    timing(fps);
   
}

void GameManager::bye() {
    for(SK::count i = 0; i < 50; i++) { cout << "=";}
    cout << "\n";
    switch(status)
    {
    case SK::Game_status::WON: 
        cout << ">>> Congratulations! You won the game.\n";
        break;
    case SK::Game_status::LOSE:
        cout << ">>> Game over! You lose the game.\n";
        break;
    default:
        break;
    }
    for(SK::count i = 0; i < 50; i++) { cout << "="; }
    cout << "\n";
}

void GameManager::summary() {
    for(SK::count i = 0; i < 50; i++) { cout <<"="; }
    cout << "\n";
    cout << "Levels loaded: " << Levels.size() << " | Snake lives: " << lives << " | Apples to eat: " << foods << '\n';
    cout << "Clear all the levels to win the game. Good luck!\n";
    for(SK::count i = 0; i < 50;i++) { cout << "=";}
    cout << "\n";
    cout << ">>> Press ENTER to start the game!\n";
    cin.get();

}

//======================[ AUXILIARY METHODS ] ======================//
bool GameManager::set_fps(int input) {
    if(input > 60 || input < 1){
        cout << ">>> WARNING: FPS chosen by user is out of the range [1,60], the default 24 will be used.\n";
        return false;
    } else {
        fps = input;
        return true;
    }
}

bool GameManager::set_lives(int input) {
    if(input > 20 || input < 1){
        cout << ">>> WARNING: LIVES chosen by user is out of the range [1,20], the default 5 will be used.\n";
        return false;
    } else {
        lives = input;
        return true;
    }
}

bool GameManager::set_foods(int input) {
    if(input > 100 || input < 1){
        cout << ">>> WARNING: FOODS chosen by user is out of the range [1,100], the default 10 will be used.\n";
        return false;
    } else {
        foods = input;
        return true;
    }
}

bool GameManager::set_playertype(string input) {
    if(strcmp(input.c_str(), "random") == 0) { 
        backtracking = false; 
        player_type = SK::Game_mode::RANDOM;
        return true;
    } else if(strcmp(input.c_str(), "backtracking") == 0)
        return true;
    
    cout << ">>> WARNING: PLAYERTYPE chosen by user is not recognized, the default <backtracking> will be used.\n";
    return false;
}

int GameManager::validate_row_collumn(string input) {
    int aux = atoi(input.c_str());
    if(aux > 100 || aux <= 0) {
        return 0;
    }
    return aux;
}

bool GameManager::is_number(const std::string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void GameManager::timing(SK::count fps) {
    // This code pauses `duration` milliseconds between frames.
    // Convert fps to milliseconds.
    std::chrono::milliseconds  duration{ 1000/fps };
    std::this_thread::sleep_for( duration );

}
void GameManager::move_rand() {
    // Create a random prior direction vector
    vector<int> options = {0,1,2,3};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(options.begin(), options.end(), std::default_random_engine{seed});

    status = SK::Game_status::LOSE;
    // Select a random direction, check if is empty and check if there is fruit
    for(int i = 0 ; i < 4; i++) {
        SK::coord next_pos =  SK::get_pos(m_snake.coord_snake(), static_cast<SK::Direct>(options[i]));
        if(Levels[curr_lvl].is_ws(next_pos) && !m_snake.is_snk(next_pos) && next_pos != m_snake.last_tail_pos) {
            if(m_snake.advance(static_cast<SK::Direct>(options[i]), Levels[curr_lvl].fruit)) {
                score += combo * 20;
                combo++;
                Levels[curr_lvl].eaten++;
                Levels[curr_lvl].fruit_spawn(m_snake.body);
            }
            status = SK::Game_status::IN_PROGRESS;
            break;
        }
    }
}

void GameManager::move_smart() {
    paths.clear();
    paths.resize(1);
    all_paths.clear();
    paths[0].pos_ = m_snake.body[0];
    paths[0].dir = m_snake.head_dir;
    choose(m_snake);
}

bool GameManager::choose(Snake temp_snk) {
    SK::coord next_pos;

    // Test if the snake is in a repeated state (same position and same head direction)
    if(all_paths.size() != 0) { 
        for(SK::count j = 0; j < all_paths.size() - 1; j++) {
            if(all_paths[j].pos_ == temp_snk.body[0] && all_paths[j].dir == temp_snk.head_dir)
                return false;   
        }
    }

    // Priority of decision of directions
    vector<int> prior = prior_list(temp_snk.body[0]);

    // Control to avoid unnecessary resizing during search
    bool control = true;

    // Go to a direction based on prior list position that wasn't been choosen and it's avaliable
    for(SK::count i = 0 ; i < 4; i++) {
        next_pos =  SK::get_pos(temp_snk.body[0], static_cast<SK::Direct>(prior[i]));
        if(Levels[curr_lvl].is_ws(next_pos) &&  next_pos != paths[paths.size()-1].pos_ && !temp_snk.is_snk(next_pos)){
            if(control) {
                paths.resize(paths.size() + 1);
                control = false;
            }
            paths[paths.size() - 1].dir = static_cast<SK::Direct>(prior[i]);
            paths[paths.size() - 1].pos_ = next_pos;
            all_paths.push_back(paths[paths.size()-1]);
            
            // Found a fruit
            if(temp_snk.advance(static_cast<SK::Direct>(prior[i]), Levels[curr_lvl].fruit)) { return true; }
            if(choose(temp_snk)) { return true;}

            // In this path didn't found the fruit
            temp_snk.undo(); 
        }
    }
    if(!control)
        paths.pop_back();
    return false;
}

void GameManager::print_dir(SK::count i) {
    switch (i)
    {
    case 0:
        cout << "UP";
        break;
    case 1:
        cout << "LEFT";
        break;
    case 2:
        cout << "DOWN";
        break;
    case 3:
        cout << "RIGHT";
        break;
    default:
        break;
    }
}

vector<int> GameManager::prior_list(SK::coord snk_head){
    vector<int> prior(4);
    // Vertical and horizontal distance
    int ver, hor;
    // If positive go UP
    ver = snk_head.y - Levels[curr_lvl].fruit.y;
    // If positive go RIGHT
    hor = Levels[curr_lvl].fruit.x - snk_head.x;
    
    // UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3
    if(abs(hor) > abs(ver)) {
        if(hor > 0) {
            prior[0] = 3; // FIRST RIGHT
            prior[2] = 1; // Choose LEFT
            } 
        else{ 
            prior[0] = 1; // FIRST LEFT
            prior[2] = 3; // Choose RIGHT
        } 
        if(ver > 0){
            prior[1] = 0; // Choose UP
            prior[3] = 2; // Choose DOWN
        } else {
            prior[1] = 2; // Choose DOWN
            prior[3] = 0; // Choose UP
        }
    }else {
        if(ver > 0){
            prior[0] = 0; // FIRST UP
            prior[2] = 2; // Choose DOWN
        } else {
            prior[0] = 2; // FIRST DOWN
            prior[2] = 0; // Choose UP
        }
        if(hor > 0) {
            prior[1] = 3; // Choose RIGHT
            prior[3] = 1; // Choose LEFT
        } 
        else{ 
            prior[1] = 1; // Choose LEFT
            prior[3] = 3; // Choose RIGHT
        } 
        
    }
    return prior;
}
