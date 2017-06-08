// OOPLab1_5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include "Triangle.h"


void PerformAction(vector<float> choose, int& ind, vector<Triangle>&v)
{
	int i;
	string s;
		switch ((int)choose[ind++])
		{
		case 1:
			i = choose[ind++];
			cout << "<h2>A: " << v[i].GetAngleA() << " B: " << v[i].GetAngleB() << " C: " << v[i].GetAngleC() << "</h2>\n";
			break;
		case 2:
			i = choose[ind++];
			cout << "<h2>Base: " << v[i].GetBase() << " A: " << v[i].GetSideA() << " B: " << v[i].GetSideB() << "</h2>\n";
			break;
		case 3:
			float newSize;
			i = choose[ind++];
			newSize = choose[ind++];
			v[i].SetBase(newSize);
			break;
		case 4:
			i = choose[ind++];
			cout << "<h2>Median A: " << v[i].GetMedianA() << " Median B: " << v[i].GetMedianB() << " Median Base: " << v[i].GetMedianBase() << "<\h2>\n";
			break;
		case 5:
			int j;
			i = choose[ind++];
			j = choose[ind++];
			if (v[i].IsSimilarTo(v[j]))
				cout << "<h2>Triangles are similar<h2>\n";
			else
				cout << "<h2>Triangles are not similar<h2>\n";
			break;
		default:
			break;
		}
		
}
vector<float> Parse(char* s)
{
	int i = 0;
	vector<float> vec;
	string str = "";
	while (s[i] != '\0')
	{
		if (s[i] != '?') {
			str += s[i];
			++i;
		}
		else
		{
			vec.push_back(atof(str.c_str()));
			str = "";
			++i;
		}
	}
	vec.push_back(atof(str.c_str()));
	return vec;
}

int main()
{
	char* s = getenv("QUERY_STRING");
	//s = "1?30?60?1?60?30?2?2?2?1?1?1?2?3?4?1";
	int ind=0;
	auto params = Parse(s);
	vector<Triangle> v;
	Triangle::initVector(v, 5,params,ind);
	cout << "Content-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title>Hello World - First CGI Program</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	cout << "<h2>Hello World! This is my first CGI program</h2>\n";
	cout << "<h2>" << s << "</h2>";
	cout << "<h2>";
	for (int i = 0; i < params.size(); i++)
		cout << params[i] << " ";
	cout << "</h2>";
	while(ind<params.size())
	{
		PerformAction(params,ind, v);
		++ind;
	} 
	cout << "</body>\n";
	cout << "</html>\n";
    return 0;
}

