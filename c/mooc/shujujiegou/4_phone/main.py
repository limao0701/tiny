#!/usr/bin/env/python3

if(__name__=="__main__"):
    start,end = input().split()
    s_strings=start.split(':')
    e_strings=end.split(':')
    start_s=int(s_strings[0])*3600 + int(s_strings[1])*60 + int(s_strings[2])
    end_s=int(e_strings[0])*3600 + int(e_strings[1])*60 + int(e_strings[2])
    if(end_s < start_s):
       end_s+=24*3600
    print(end_s - start_s)
