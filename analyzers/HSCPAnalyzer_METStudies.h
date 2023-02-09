#ifndef DEF_HSCPAnalyzer_METStudies
#define DEF_HSCPAnalyzer_METStudies

#include "RazorAnalyzer.h"

class HSCPAnalyzer_METStudies: public RazorAnalyzer {
    public: 
        HSCPAnalyzer_METStudies(TTree *tree=0): RazorAnalyzer(tree) { }
        void Analyze(bool isData, int option, string outputFileName, string label);
};

#endif
