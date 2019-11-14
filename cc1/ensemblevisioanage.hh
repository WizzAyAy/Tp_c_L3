#include "visionage.hh"
#include <vector>
#include <string>

class ensemblevisioanage
{
public:
    ensemblevisioanage();
    ~ensemblevisioanage();
    void afficherlesvisionage();
    void ajoutervisionage(visionage const & v);
    void afficherlesserie()const;
    void afficherannee(const unsigned int &a)const;
    int nombredesaga()const;
    bool dejadedans(std::string const & titresaga, const std::vector<std::string> &temp)const;
private:
    std::vector<visionage *> _ensemble;
};

