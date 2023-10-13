#include<bits/stdc++.h>
using namespace std;

class UrlShortener {
private:
    unordered_map<string,string> urlMap;
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int shortUrlLength = 6;

public:
    string generateShortUrl() {
        string shortUrl;
        int charactersLength = characters.length();
        for (int i = 0; i < shortUrlLength; ++i) {
            int randIndex = rand() % charactersLength;
            shortUrl.push_back(characters[randIndex]);
        }
        return shortUrl;
    }

    string shortenUrl(const string& longUrl) {
        string shortUrl = generateShortUrl();
        urlMap[shortUrl] = longUrl;
        return shortUrl;
    }

    string getLongUrl(const string& shortUrl) {
        if (urlMap.find(shortUrl) != urlMap.end()) {
            return urlMap[shortUrl];
        }
        return "URL not found.";
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    UrlShortener urlShortener;
    string longUrl, shortUrl;

    cout << "Enter the long URL to shorten: ";
    cin >> longUrl;

    shortUrl = urlShortener.shortenUrl(longUrl);
    cout << "Shortened URL: " << shortUrl << std::endl;

    string retrievedUrl = urlShortener.getLongUrl(shortUrl);
    cout << "Retrieved URL: " << retrievedUrl << std::endl;

    return 0;
}
