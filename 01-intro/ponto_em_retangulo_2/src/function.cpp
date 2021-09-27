/*! 
 * Given a rectangle, checks whether a point is on the inside, 
 * outside or on the margin.
 *
 * @param IE Pointer to the coordinates of the lower left vertex
 *     of the rectangle.
 * @param SD Pointer to the coordinates of the upper right vertex
 *     of the rectangle.
 * @param P Pointer to the coordinates of the point to be analyzed.
 * @return An integer, which can be 0, 1 or 2, indicating, respectively,
 *     whether the point is inside, on the margin or outside the
 *     rectangle.
 */

#include "function.h"

location_t pt_in_rect( const Ponto &IE, const Ponto &SD, const Ponto &P )
{
    if((IE).x < (P).x && (P).x < (SD).x && (IE).y < (P).y && (P).y < (SD).y) return INSIDE;
    else if ((P).x == (IE).x && (P).y >= (IE).y && (P).y <= (SD).y) return BORDER;
    else if ((P).x == (SD).x && (P).y >= (IE).y && (P).y <= (SD).y) return BORDER;
    else if ((P).y == (IE).y && (P).x >= (IE).x && (P).x <= (SD).x) return BORDER;
    else if ((P).y == (SD).y && (P).x >= (IE).x && (P).x <= (SD).x) return BORDER;
    else return OUTSIDE;
}