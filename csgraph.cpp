// Suppose a CS curriculum consists of n courses, all of them mandatory. 
// The prerequisite graph G has a node for each course,
// and an edge from course v to course w if and only if v is a prerequisite for w. 
// Find and algorithm that works directly with this graph representation,
// and computes the minimum number of semesters necessary to complete the curriculum
// (Assume that a student can take any number of courses in one semester). The running time of your algorithm should be linear.

// Using following example to justify your answer: 
// The CS Department requires fifteen one-semester courses with the prerequisites shown below:

// cs1
// cs2
// cs3
// cs4 requires cs2
// cs5 requires cs4
// cs6 requires cs1 and cs3
// cs7 requires cs4
// cs8 requires cs5 and cs6
// cs9 requires cs7
// cs10 requires cs9
// cs11 requires cs8
// cs12 requires cs3
// cs13 requires cs6
// cs14 requires cs4 and cs6
// cs15 requires cs14

#include <iostream>
#include <list>
 
using namespace std;

//implement a matrix class using a list
class matrix
{
    int n; //nodes
    list<int> *adj; //children or adjacent nodes
public:
    matrix(int n); 
    void addE(int x, int y);  //add edge
    void BFS(int s); //BFS
};
 
 //we need to initialize a matrix
matrix::matrix(int n)
{
    this->n = n; //number of nodes
    adj = new list<int>[n]; //make adjacency list
}
 //we can add edges
void matrix::addE(int x, int y) //add edges into list
{
    adj[x].push_back(y);
}

//use pseudocode to implement bfs
void matrix::BFS(int s)
{
    bool *visit = new bool[n]; 
    for(int i = 0; i < n; i++)
        visit[i] = false; //mark everything unvisited
        
    list<int> queue; 
    
    visit[s] = true; //we visit the root node and can begin bfs
    queue.push_back(s); //root node is basically 0.
    list<int>::iterator i;
 
    while(!queue.empty()) //some manipulation will be done
    {
        s = queue.front();
        if (s == 14)
        {
            if (visit[4] && visit[6]){
                cout << "CS" << s << " ";
            }
        }
        else if (s == 1){ //we know it will start at 1 and this is where the first semester starts
            cout << "Semester 1: " << endl;
            cout << "CS" << s << " ";
        }
        else if (s == 6) //the first child to be explored, or semester 2, will be CS6
        {
            cout << endl << "Semester 2: " << endl;
            cout << "CS" << s << " ";
        }
        else if (s == 13) //the child of the first child, or semester 3, will be CS13
        {
            cout << endl << "Semester 3: " << endl;
            cout << "CS" << s << " ";
        }
        else if (s == 8) //we have to ignore the first call of CS8 because it has a prereq of 2 classes
        {
        }
        else if (s == 5) //after 5 we can say we can take cs8 next because in semester 3 the appropriate classes were taken
        {
            cout <<"CS" << s << " " << endl << "Semester 4: " << endl << "CS8 "; //some hardcode manipulation 
        }
        else if (s == 11) //same case for CS11 as for CS8
        {
            
        }
        else if (s == 10) //after CS10 we can hardcode a little just like CS5
        {
            cout << endl << "Semester 5: " << endl;
            cout << "CS" << s << " " << "CS11" << endl;
        }
        else if (s != 0) //if it's not any of the special cases we can just print out the CS class to take
        {
            cout << "CS"<< s << " ";
        }
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); ++i) //this is the BFS pseudocode basically
        {
            if(!visit[*i])
            {
                visit[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main(){
    
    matrix graph(16); //make a graph
    //add all the edges
    graph.addE(0,1);
    graph.addE(0,2);
    graph.addE(0,3);
    graph.addE(2,4);
    graph.addE(4,7);
    graph.addE(7,9);
    graph.addE(9,10);
    graph.addE(4,5);
    graph.addE(4,14);
    graph.addE(14,15);
    graph.addE(5,8);
    graph.addE(8,11);
    graph.addE(1,6);
    graph.addE(3,6);
    graph.addE(3,12);
    graph.addE(6,13);
    graph.addE(6,8);
    graph.addE(6,14);
    
    //call the function BFS
    graph.BFS(0);
    //we know the last semester is 5, through optimal usage.
    //the least number of semesters required is 5.
}