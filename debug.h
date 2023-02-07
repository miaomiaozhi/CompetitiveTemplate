#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
#define LOG(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(auto v) {
  return to_string(v);
}

string to_string(char c) {
  return string("") + c;
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename T>
string to_string(vector <T> v) {
  bool first = true;
  string res = "[";
  for (const T &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}

template <typename T> 
string to_string(set <T> s) {
  bool first = true;
  string res = "{";
  for (const T &x : s) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename T> 
string to_string(multiset <T> s) {
  bool first = true;
  string res = "{";
  for (const T &x : s) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename K, typename V> 
string to_string(unordered_map <K, V> x) {
  bool first = true;
  string res = "{";
  for (const auto &[k, v] : x) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "(" + to_string(k) + ", " + to_string(v) + ")";
  }
  res += "}";
  return res;
}

template <typename K, typename V> 
string to_string(map <K, V> x) {
  bool first = true;
  string res = "{";
  for (const auto &[k, v] : x) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "(" + to_string(k) + ", " + to_string(v) + ")";
  }
  res += "}";
  return res;
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}