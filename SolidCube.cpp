#include<iostream>

#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

struct FacetNormal {
    
    double x{}, y{}, z{}; 

};

int main()

{

    ifstream in;
    ofstream out;
    in.open("model.txt");
    out.open("SolidCube.txt");

    vector<FacetNormal> vertices;
    double s1,s2,s3;
    string s;
    FacetNormal normal;
    map <string , vector<vector<FacetNormal>>> m1;
    if(in){
    while(in.eof() == 0)

    {

      getline(in,s);

      //s.erase(0,s.find_first_not_of(" \t"));
      // std::cout<<std::endl<<std::endl<<s.substr(s.find("facet")+13,3)<<std::endl<<std::endl;

       vector<FacetNormal> vec;
      if(s.find("facet") != s.npos)
      {
      
      while(s!= "endfacet"){
       if(s.compare(0,6, "vertex") == 0)
        {
          FacetNormal n1;
          n1.x = stod(s.substr(13,3));
          n1.y = stod(s.substr(17,3));
          n1.z = stod(s.substr(21,3));
          vec.push_back(n1);
        }
      }
      }
     if(m1.find(s.substr(s.find("facet")+13, 24)) != m1.end())
        {
          m1[s.substr(s.find("facet")+13, 24)].push_back(vec);
        }
      else{
        vector<vector<FacetNormal>> v;
        v.push_back(vec);
        m1[s.substr(s.find("facet")+13, 24)] = v;
      }
    }
    }
    in.close();
    

    for(auto m : m1){
        if (stod(m.first.substr(0,3)) == 1.0)
        {
          out<< (2.0)*m.second[0][0].x<<" "<< m.second[0][1].y<<" "<< m.second[0][2].z;
          out<< (2.0)*m.second[1][0].x <<" "<< m.second[1][1].y<<" "<<m.second[1][2].z;
          out<< (2.0)*m.second[2][0].x <<" "<< m.second[2][1].y<<" "<<m.second[2][2].z;
          out<< (2.0)*m.second[3][0].x <<" "<< m.second[3][1].y<<" "<<m.second[3][2].z;
          out<< (2.0)*m.second[4][0].x <<" "<< m.second[4][1].y<<" "<<m.second[4][2].z;
          out<< (2.0)*m.second[5][0].x <<" "<< m.second[5][1].y<<" "<<m.second[5][2].z;

        }
        if (stod(m.first.substr(5,7)) == 1.0)
        {
          out<< m.second[0][0].x<<" "<< (2.0)*m.second[0][1].y<<" "<< m.second[0][2].z;
           out<< m.second[1][0].x<<" "<< (2.0)*m.second[1][1].y<<" "<< m.second[1][2].z;
           out<< m.second[1][0].x<<" "<< (2.0)*m.second[2][1].y<<" "<< m.second[2][2].z;
           out<< m.second[3][0].x<<" "<< (2.0)*m.second[3][1].y<<" "<< m.second[3][2].z;
           out<< m.second[4][0].x<<" "<< (2.0)*m.second[4][1].y<<" "<< m.second[4][2].z;
           out<< m.second[5][0].x<<" "<< (2.0)*m.second[5][1].y<<" "<< m.second[5][2].z;
        }
        if (stod(m.first.substr(9,11)) == 1.0)
        {
           out<< m.second[0][0].x<<" "<< m.second[0][1].y<<" "<< (2.0)*m.second[0][2].z;
          out<< m.second[1][0].x<<" "<< m.second[1][1].y<<" "<< (2.0)*m.second[1][2].z;
          out<< m.second[2][0].x<<" "<< m.second[2][1].y<<" "<< (2.0)*m.second[2][2].z;
         out<< m.second[3][0].x<<" "<< m.second[3][1].y<<" "<< (2.0)*m.second[3][2].z;
          out<< m.second[4][0].x<<" "<< m.second[4][1].y<<" "<< (2.0)*m.second[4][2].z;
          out<< m.second[5][0].x<<" "<< m.second[5][1].y<<" "<< (2.0)*m.second[5][2].z;
        }
        if (stod(m.first.substr(0,3))== -1.0)
        {
          out<< (-2.0)*m.second[0][0].x<<" "<< m.second[0][1].y<<" "<< m.second[0][2].z;
          out<< (-2.0)*m.second[1][0].x <<" "<< m.second[1][1].y<<" "<<m.second[1][2].z;
          out<< (-2.0)*m.second[2][0].x <<" "<< m.second[2][1].y<<" "<<m.second[2][2].z;
          out<< (-2.0)*m.second[3][0].x <<" "<< m.second[3][1].y<<" "<<m.second[3][2].z;
          out<< (-2.0)*m.second[4][0].x <<" "<< m.second[4][1].y<<" "<<m.second[4][2].z;
          out<< (-2.0)*m.second[5][0].x <<" "<< m.second[5][1].y<<" "<<m.second[5][2].z;
        }
        if (stod(m.first.substr(5,7)) == -1.0)
        {
          
          out<< m.second[0][0].x<<" "<< (-2.0)*m.second[0][1].y<<" "<< m.second[0][2].z;
           out<< m.second[1][0].x<<" "<< (-2.0)*m.second[1][1].y<<" "<< m.second[1][2].z;
           out<< m.second[1][0].x<<" "<< (-2.0)*m.second[2][1].y<<" "<< m.second[2][2].z;
           out<< m.second[3][0].x<<" "<< (-2.0)*m.second[3][1].y<<" "<< m.second[3][2].z;
           out<< m.second[4][0].x<<" "<< (-2.0)*m.second[4][1].y<<" "<< m.second[4][2].z;
           out<< m.second[5][0].x<<" "<< (-2.0)*m.second[5][1].y<<" "<< m.second[5][2].z;
        }
        else
        {
           out<< m.second[0][0].x<<" "<< m.second[0][1].y<<" "<< (-2.0)*m.second[0][2].z;
          out<< m.second[1][0].x<<" "<< m.second[1][1].y<<" "<< (-2.0)*m.second[1][2].z;
          out<< m.second[2][0].x<<" "<< m.second[2][1].y<<" "<< (-2.0)*m.second[2][2].z;
         out<< m.second[3][0].x<<" "<< m.second[3][1].y<<" "<< (-2.0)*m.second[3][2].z;
          out<< m.second[4][0].x<<" "<< m.second[4][1].y<<" "<< (-2.0)*m.second[4][2].z;
          out<< m.second[5][0].x<<" "<< m.second[5][1].y<<" "<< (-2.0)*m.second[5][2].z;
        }
     }
out.close();



return 0;
}