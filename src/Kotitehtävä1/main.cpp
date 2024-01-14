#include <iostream>
#include <cstdlib>
#include <ctime>
int game(int max){
    std::srand(std::time(0));

    int oikeaLuku = std::rand() % max+1;
int arvauksienmäärä=1;
std::cout << "Arvaa luku välillä 1-"<< max << std::endl;

    int arvaus;
    do {
        std::cout << "Arvaa luku: ";
        std::cin >> arvaus;

        if (arvaus < oikeaLuku) {
            std::cout << "Luku on suurempi." << std::endl;
        } else if (arvaus > oikeaLuku) {
            std::cout << "Luku on pienempi." << std::endl;
        } else {
            std::cout << "Oikea vastaus!" << std::endl;
            break;
        }
arvauksienmäärä++;
    } while (true);
    return arvauksienmäärä;
}
int main() {
   int arvauksienmäärä=game(40);
   std::cout << "Arvauksin Määrä : "<<arvauksienmäärä << std::endl;

   return 0;
}
