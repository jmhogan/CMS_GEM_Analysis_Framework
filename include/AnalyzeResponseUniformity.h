//
//  AnalyzeResponseUniformity.h
//  
//
//  Created by Brian L Dorney on 28/01/16.
//
//

#ifndef ____AnalyzeResponseUniformity__
#define ____AnalyzeResponseUniformity__

//C++ Includes
#include <stdio.h>
#include <string>
#include <map>

//Framework Includes
//#include "DetectorMPGD.h"
#include "TimingUtilityFunctions.h"
#include "TimingUtilityTypes.h"
#include "UniformityUtilityTypes.h"

//ROOT Includes
#include "TROOT.h"

namespace Uniformity {
    class AnalyzeResponseUniformity {
        
    public:
        //Constructors
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Default
        AnalyzeResponseUniformity();
        
        //Declare the detector and the requested granularity
        //AnalyzeResponseUniformity(int iNSlices, Uniformity::DetectorMPGD inputDet);
        
        //Set the detector and anlysis parameters at construction
        AnalyzeResponseUniformity(Uniformity::AnalysisSetupUniformity inputSetup, Uniformity::DetectorMPGD inputDet);
        
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Filling*****************
        //Loops over all stored clusters in detMPGD and Book histograms for the full detector
        void fillHistos();
        
        //Loops over all stored clusters in a specific iEta sector of detMPGD and Book Histograms
        //void fillHistos(int iEta);
        //void fillHistos(SectorEta &inputEta);
        
        //Loops over all stored clusters in a specific iPhi sector of detMPGD and Book Histograms
        //void fillHistos(int iEta, int iPhi);
        //void fillHistos(SectorPhi &inputPhi);
        
        //NOTE: NOT IMPLEMENTED YET
        //Fitting*****************
        //Loops over all slices in detMPGD and fits Booked histograms for the full detector
        //void fitHistos();
        
        //Loops over all slices in a specific iEta sector of detMPGD and fits Booked Histograms
        //void fitHistos(int iEta);
        
        //Loops over all slices in a specific iPhi sector of detMPGD and fits Book Histograms
        //void fitHistos(int iEta, int iPhi);
        
        //Storing*****************
        //Stores booked histograms (for those histograms that are non-null)
        void storeHistos(std::string strOutputROOTFileName, std::string strOption);
        
        //Stores booked fits (for those fits that are non-null)
        //void storeFits(std::string strOutputROOTFileName, std::string strOption);
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        Uniformity::DetectorMPGD getDetector(){ return detMPGD; };
        
        //Printers - Methods that Print Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        
        //Setters - Methods that Set Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Sets the Analysis Setup
        void setAnalysisParameters(Uniformity::AnalysisSetupUniformity inputSetup){ aSetup = inputSetup; return; };
        
        //Sets the Detector
        void setDetector(Uniformity::DetectorMPGD inputDet){ detMPGD = inputDet; return; };
        
        //Sets the requested response granularity;
        //void setResponseGranularity(int iInput){ iNSlices = iInput; return; };
        
    private:
        //Actions - Methods that Do Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        //Filling*****************
        //Loops over all stored clusters in a specific iEta sector of detMPGD and Book Histograms
        //void fillHistos(int iEta);
        void fillHistos(SectorEta &inputEta);
        
        //Loops over all stored clusters in a specific iPhi sector of detMPGD and Book Histograms
        //void fillHistos(int iEta, int iPhi);
        void fillHistos(SectorPhi &inputPhi);
        
        //Getters - Methods that Get (i.e. Return) Something
        //------------------------------------------------------------------------------------------------------------------------------------------
        TH1F getHistogram(int iEta, int iPhi, Timing::HistoSetup &setupHisto);
        
        
        //Data Members
        //------------------------------------------------------------------------------------------------------------------------------------------
        Timing::HistoSetup hSetupClust_ADC, hSetupClust_Multi, hSetupClust_Pos, hSetupClust_Size;
        
        Uniformity::AnalysisSetupUniformity aSetup;
        
        Uniformity::DetectorMPGD detMPGD; //Link to header file in AnalyzeResponseUniformity.cpp
        
    }; //End class AnalyzeResponseUniformity
} //End namespace Uniformity


#endif /* defined(____AnalyzeResponseUniformity__) */