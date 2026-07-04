/*
********************************************************************************
                         Theory Of Algorithms (CS222)
Name: Motaz Ahmad Algawagneh                ID:20231502067
                    
مشروع شبكة مدينة عمان   
(تمثيل ومحاولة محاكاة 8 معالم بارزة في عمان والمسافات بينهم بالكيلو متر)
********************************************************************************
الأماكن:

// Index  | Code   |  Name
********************************************************************************
//   0    | GJU    | German Jordanian University

//   1   |  UH    | Jordan University Hospital

//   2   |  PAR   | Jordanian Parliament
 
//   3   |  ABD   | Abdali Boulevard
 
//   4   |  CIT   | City Mall
  
//   5   |  ROM   | Roman Theater
   
//   6   |  AIR   | Queen Alia International Airport
   
//   7   |  STA  | Amman International Stadiu

*/

#include <iostream>
#include <climits>
#include <iomanip>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int V=8;




void dijkstra(double roads[V][V],int source,string placeNames[]){
double distTo[V]; 
int edgeTo[V]; 
for(int i=0;i<V;i++){
distTo[i]=INT_MAX;
edgeTo[i]=-67;
}
distTo[source]=0;

priority_queue< pair<double,int>,vector< pair<double,int> >,greater< pair<double,int> > > pq;

for(int i=0;i<V;i++){
pq.push({distTo[i],i});
}

while(!pq.empty()){
int v = pq.top().second;
pq.pop();
for(int w=0;w<V;w++){
if(roads[v][w]==-67)
continue;
if(distTo[v]+roads[v][w]<distTo[w]){
distTo[w]=distTo[v]+roads[v][w];
edgeTo[w]=v;
pq.push({distTo[w],w});
}}}

cout <<"\nDijkstra Results from "<<placeNames[source]<<"\n\n";
for(int i=0;i<V;i++){
cout <<"To "<<placeNames[i]<<": "<<distTo[i]<<" km\n";
}}








void primMST(int source,double roads[V][V],string placeNames[]){
 double key[V];
 bool inprimQ[V];
 int parent[V];
 
for(int i=0;i<V;i++){
key[i]=INT_MAX;
inprimQ[i]=true;
parent[i]=-67;
}
key[source]=0;
priority_queue< pair<double,int>,vector< pair<double,int> >,greater< pair <double,int> > >primQ;
for(int j=0;j<V;j++){
primQ.push({key[j],j});
} 


while(!primQ.empty()){
int min=primQ.top().second;
primQ.pop();

if(!inprimQ[min])
continue;
inprimQ[min]=false;

for(int v=0;v<V;v++){
if(roads[min][v]!=-67 && inprimQ[v] && roads[min][v]<key[v]){
parent[v]=min;
key[v]=roads[min][v];
primQ.push({key[v],v});
}}}


double totalWeight = 0;
for(int v=0;v<V;v++){
if(parent[v]!=-67){
cout<<placeNames[parent[v]]<<" -> "<<placeNames[v]<<" : "<<key[v]<<" km\n";
totalWeight=totalWeight+key[v];
}}
cout<<"\nTotal MST Distance: "<<totalWeight<<" km\n";    
}






void BFT(int source,double roads[V][V],string placeNames[]){
bool marked[V];
int parent1[V];
double distTo1[V];
for(int i=0;i<V;i++){
marked[i]=false;
parent1[i]=-67;
distTo1[i]=INT_MAX;
}
marked[source]=true;
distTo1[source]=0;
queue<int> BFTqueue;
BFTqueue.push(source);

while(!BFTqueue.empty()){
int m=BFTqueue.front();
BFTqueue.pop();
for(int w=0;w<V;w++){
if(roads[m][w]!=-67 && !marked[w]){
marked[w]=true;
distTo1[w]=distTo1[m]+roads[m][w];
parent1[w]=m;
BFTqueue.push(w);
}
}
}
cout<<"\nBFT Results from "<<placeNames[source]<<"\n";
for(int i=0;i<V;i++){
if(distTo1[i] == INT_MAX){
cout << "To " << placeNames[i] << ": No path";
}else{
cout << "\nTo " << placeNames[i]<< "  Distance = " << distTo1[i]<< " km "<<" Parent: ";
if(parent1[i] == -67)
cout << "None";
else
cout << placeNames[parent1[i]]<<endl;
}}}








int main(){
double roads[8][8];
string placeNames[8]={"GJU","UH","PAR","ABD","CIT","ROM","AIR","STA"};
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
roads[i][j]=-67;
}
}
roads[2][3]=roads[3][2]=1.2;
roads[7][3]=roads[3][7]=2.5;
roads[1][7]=roads[7][1]=3;
roads[3][1]=roads[1][3]=4;
roads[2][5]=roads[5][2]=2;
roads[3][5]=roads[5][3]=2.2;
roads[3][4]=roads[4][3]=7;
roads[7][4]=roads[4][7]=6;
roads[3][6]=roads[6][3]=28;
roads[5][6]=roads[6][5]=30;
roads[6][0]=roads[0][6]=10;
roads[3][0]=roads[0][3]=23;
cout << "========================================\n";
cout << "   Amman City Network Optimization\n";
cout << "   Theory of Algorithms (CS222) Project\n";
cout << "========================================\n\n";
cout<<"DIRECT ROAD CONNECTIONS:\n";
for(int i=0;i<8;i++){
cout<<placeNames[i]<<" Which is # "<<i<<" in our Graph "<<" connects to:\n";
int connectionCount=0;
for(int j=0;j<8;j++){
if(roads[i][j] !=-67){
cout<<" -> "<<placeNames[j]<<""<<" Which is # "<<j<<" in our Graph "<<roads[i][j]<<" km\n";
connectionCount++;
}}
cout<<" Total connections in this node (node # "<<i<<") : "<<connectionCount<<"\n\n";
}
int source;
cout<<"Choose starting point:\n";
cout<<"0. GJU (University)\n";
cout<<"1. Jordan University Hospital (Hospital)\n";
cout<<"2. Jordanian Parliament (Government)\n";
cout<<"3. Abdali Boulevard (Business / Commercial)\n";
cout<<"4. City Mall (Commercial)\n";
cout<<"5. Roman Theater (Cultural / Tourism)\n";
cout<<"6. Queen Alia International Airport (Transportation)\n";
cout<<"7. Amman International Stadium (Sports / Public Facility)\n";
cout<<"\n";
cout<<"Enter choice (0-7): ";
cin>>source;
cout<<"\n";
if(7<source || 0>source)
cout<<"Error! Please enter a number between 0 and 7.\n"<<endl;
dijkstra(roads,source,placeNames);
cout << "\nPRIM MST Results from "<<placeNames[source]<<endl;
primMST(source,roads,placeNames);
BFT(source,roads,placeNames);
return 0;
}

