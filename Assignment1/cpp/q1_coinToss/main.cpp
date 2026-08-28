#include <iostream>
#include <random>
#include <fstream>




void two_coin_exp(int total_tosses) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 1);

    std::fstream file("two_coin_toss.csv", std::ios::out | std::ios::in | std::ios::trunc);

    if(!file.is_open()) throw std::runtime_error("Failed to open file for writing.");

    file << "TossCount,HH,P(HH),HT,P(HT),TH,P(TH),TT,P(TT)" << "\n";

    int hh = 0;
    int ht = 0;
    int th = 0;
    int tt = 0;

    int toss_count = 0;

    for(int i = 1; i <= total_tosses; i++) {
        int result1 = distrib(gen);
        int result2 = distrib(gen);

        if(result1 && result2) {
            hh++;
        } else if(result1 && !result2) ht++;
        else if(!result1 && result2) th++;
        else tt++;

        toss_count++;

        double probHH = (hh*1.0)/toss_count;
        double probHT = (ht*1.0)/toss_count;
        double probTH = (th*1.0)/toss_count;
        double probTT = (tt*1.0)/toss_count;

        file << toss_count << "," << hh << "," << probHH << "," << ht << "," << probHT << "," << th << "," << probTH << "," << tt << "," << probTT << "\n";
        
    }

    std::cout << "P(hh): " << (hh * 1.0) / total_tosses << "\n";
    std::cout << "P(ht): " << (ht * 1.0) / total_tosses << "\n";
    std::cout << "P(th): " << (th * 1.0) / total_tosses << "\n";
    std::cout << "P(tt): " << (tt * 1.0) / total_tosses << "\n";
}


void one_coin_exp(int total_tosses) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(0, 1);


    std::fstream file("one_coin_toss.csv", std::ios::out | std::ios::in | std::ios::trunc);

    if(!file.is_open()) throw std::runtime_error("Failed to open file for writing.");

    file << "TossCount,HeadCount,P(Head),TailCount,P(Tail)" << "\n";

    int heads = 0;
    int tails = 0;

    int toss_count = 0;

    for(int i = 1; i <= total_tosses; i++) {
        int result = distrib(gen);

        if(result) heads++;
        else tails++;
        toss_count++;

        double probHead = (heads * 1.0) / toss_count;
        double probTail = (tails * 1.0) / toss_count;

        file << toss_count << "," << heads << "," << probHead << "," << tails << "," << probTail << "\n";

    }

    std::cout << "P(head): " << (heads * 1.0) / total_tosses << "\n";
    std::cout << "P(tails): " << (tails * 1.0) / total_tosses << "\n";
}


int main() {
    int total_tosses = 1e5;

    // One coin experiment
    one_coin_exp(total_tosses);
    // two coin experiment
    two_coin_exp(total_tosses);

}