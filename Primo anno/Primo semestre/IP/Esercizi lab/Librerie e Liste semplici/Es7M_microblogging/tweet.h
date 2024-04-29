#ifndef TWEET_H
#define TWEET_H  

#include <string>
#include <vector>

struct Tweet{
	std::string text;
	std::vector<std::string> hashtags; // elenco di hashtags
};

void tweetwrite(Tweet t);

Tweet tweetread();

#endif
