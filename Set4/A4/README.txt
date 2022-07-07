/* CSCI 261: A4 - Abstract Lists: Wavefront OBJ File Validator
 *
 * Author: Kylie Quinney
 * Resources used: none
 *
 * read in a simplified Wavefront OBJ file, validate if it would correctly form a model, and print out the data that makes up the model
 */
 
1) I used a linked list
2) My main issue was that I could not figure out how to read the file in and append the numbers as ints or floats, I had to read them in as strings ( reading them in as ints just gave me the ascii value).
3) Yes, I think it may have been the more difficult choice, but that might be because I ma not that familiar with linked lists
4) I read in the first ccharector of each line and based on what that was (#, V, or f), I added the rest of the line to a node on the linked list
5) (for validating the faces) I couldn't even figure it out, I had trouble with accessing certain indexes within the node value; (for making sure the file itself ould open) I hade no issues
6)For validating faces yes, I think it was more difficult; for validating that the file itself could open, no it doesn't matter wich data structure you use
7 & 8) The linked list did not cause any issues with printing the  data from the file
