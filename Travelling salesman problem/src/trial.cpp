#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

float dist[1000][1000];
int noc;
float totaldistance;
int done=0;
float coord[1000][2];
class tsp
{
    public:
    int nearest_neighbourB(int start);
    void nearest_neighbour();
    int two_exchange();
    int two_opt();
    int swap_two(int i,int k);
    bool issafe(int n);
    float get_distance();
private:

    vector<int> solution;
    vector<int> visited;
    vector<int> notvisited;


};
bool tsp::issafe(int n)
{
    //if(dist[solution[cityvisited-1]][start] )
    for(int i=0;i<visited.size();i++)
    {
        if(n==visited[i])
            return false;
    }
    return true;

}
int tsp::nearest_neighbourB(int start)
{
    int flag=0;
    int cityvisited=0;
    float mindistance=9999999.0;
    totaldistance=0;
    float currentdist=0;
    int nearindex=0;
    int unvisited=noc;
    solution.clear();
    visited.clear();
    solution.push_back(start);
    visited.push_back(start);
    --unvisited;
    ++cityvisited;
    while(unvisited!=0)
          {
              flag=0;
              mindistance=9999999.0;
                for(int i=0;i<noc;i++)
                {

                    if((issafe(i)==true &&  dist[solution[cityvisited-1]][i]!=0.0))
                    {
                    currentdist=dist[solution[cityvisited-1]][i];
                    if(currentdist<mindistance)
                    {
                        nearindex=i;
                        mindistance=currentdist;
                        flag=1;

                    }
                }
                }
                if(flag==1)
                {
                totaldistance+=mindistance;
                solution.push_back(nearindex);
                visited.push_back(nearindex);
                ++cityvisited;

                }
                --unvisited;
          }
          if(visited.size()==noc && dist[solution[cityvisited-1]][solution[0]]!=0.0)
          {
              totaldistance+=dist[solution[cityvisited-1]][solution[0]];
              return 1;
          }
          else
          {
              return 0;
          }


}
void tsp::nearest_neighbour()
{
    float bestoutput=99999999;
    float lastoutput=0;
    int f=0,flag=0;
    for(int i=0;!done && i<noc;i++)
    {
        f=nearest_neighbourB(i);
        if(f==1)
        {
        lastoutput=two_exchange();
        if(totaldistance<bestoutput)
        {
            bestoutput=totaldistance;
            //cout<<"solution:"<<endl;
            for(int j=0;j<solution.size();j++)
            {
                cout<<solution[j]<<" ";
            }
            cout<<endl;
            //cout<<"distance:"<<bestoutput<<endl;
            flag=1;

        }
        }
        else
        {
            continue;
        }

    }
    if(flag!=1)
    {
        cout<<"No path existed"<<endl;
    }
}
int tsp::two_exchange()
{
    float mindist=totaldistance;
    bool flag=false;
    //cout<<"loop enter"<<endl;
    while(!done)
    {
        flag=false;
        for(int i=1;i<noc && !flag;i++)
        {
            for(int j=i+1;j<noc-1 && !flag;j++)
            {
                if((dist[solution[i-1]][solution[j]]+dist[solution[i]][solution[j+1]])<dist[solution[i-1]][solution[i]]+dist[solution[j]][solution[j+1]])
                {
                    swap_two(i,j);
                    mindist=get_distance();
                    flag=true;
                }
                else{
                    flag=false;
                }
            }
        }
            if(!flag)
                break;
        }
        //cout<<"middist:"<<mindist<<endl;
        return mindist;
    }
int tsp::swap_two(int i,int k)
{
    vector<int> temp;
    int count=0;
    for(int x=k;x>=i;--x)
    {
        temp.push_back(solution[x]);
    }
    for(int x=i;x<=k;x++)
    {
        solution[x]=temp[count];
        ++count;
    }

    temp.clear();
    return 1;
}
float tsp::get_distance()
{
    float totaldist=0;
   for(int i=0;i<noc;i++)
   {
       totaldist+=dist[solution[i]][solution[i+1]];
   }
   totaldist+=dist[solution[noc-1]][solution[0]];
    return totaldist;

}
int main()
{ tsp obj;
    string ch,str="euclidean",str1="non euclidean";
    getline(cin,ch);
    cin>>noc;
    for(int i=0;i<noc;i++)
    {
        for(int j=0;j<2;j++)
        {

            cin>>coord[i][j];
        }
    }
    for(int i=0;i<noc;i++)
    {
        for(int j=0;j<noc;j++)
        {

            cin>>dist[i][j];
        }
    }
    if(ch==str)
    {
    obj.nearest_neighbour();
    }
    else if(ch==str1)
    {
        obj.nearest_neighbour();
    }
  
return 0;
}
