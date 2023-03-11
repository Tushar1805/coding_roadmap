/********** Get Problem Here **********/
// https://www.hackerrank.com/challenges/one-week-preparation-kit-time-conversion/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=preparation-kits&playlist_slugs%5B%5D=one-week-preparation-kit&playlist_slugs%5B%5D=one-week-day-one&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen


// Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

// Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
// - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

#include<iostream>
#include<sstream>
using namespace std;

string timeConversion(string s) {
    stringstream obj; 
    string result;
    string is_day = s.substr(8, 9);
    if (is_day == "PM") {
        string hr =  s.substr(0, 2);
        int int_hr;
        obj << hr;
        obj >> int_hr;
        if (int_hr < 12 ) {
            int_hr += 12; 
            obj.clear();
            obj << int_hr;
            obj >> hr;
        }
        result = s;
        result.replace(0, 2, hr);
        result.erase(8, 9);
    }else{
        string hr =  s.substr(0, 2);
        int int_hr;
        obj.clear();
        obj << hr;
        obj >> int_hr;
        if (int_hr == 12 ) {
            hr = "00";
        }
        result = s;
        result.replace(0, 2, hr);
        result.erase(8, 9);
    }
    return result;
}

int main(int argc, char const *argv[])
{
	string s, r;
	cout<<"Enter time in 12 hr clock format eg. [hh:mm:ssAM]: ";
	cin>>s;
	r = timeConversion(s);
	cout<<"\nTime in 24 hr format: "<<r;
	return 0;
}