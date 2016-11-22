//
//  DetectorSuperchamber.cpp
//  
//
//  Created by Brian L Dorney on 17/11/16.
//
//

#include "DetectorSuperchamber.h"

using std::map;
using std::shared_ptr;
using std::string;

using namespace QualityControl::Timing;

DetectorSuperchamber::DetectorSuperchamber(){
    m_dDetAND = m_dDetOR = -1.;
    m_dDetDelta = 0.;
    
    m_strName = "Superchamber";
};

void DetectorSuperchamber::calcAndDeltaOr(){
    map<string, double> map_detTime;
    
    for (auto iterDet = m_map_detectors.begin(); iterDet != m_map_detectors.begin(); ++iterDet) {
        map_detTime[(*iterDet).second.getBaseAddress()]=(*iterDet).second.getChannelOR();
    }
    
    m_dDetAND = getMaxForChannelAND(map_detTime);
    m_dDetOR = getMinForChannelOR(map_detTime);
    
    m_dDetDelta = getDeltaTForChannel(m_dDetAND, m_dDetOR);
    
    return;
} //End DetectorSuperchamber::calcAndDeltaOr()

void DetectorSuperchamber::reset(){
    m_strName.clear();
    m_map_strBaseAddr2iDetPos.clear();
    m_map_detectors.clear();
    
    return;
} //End DetectorSuperchamber::reset()

void DetectorSuperchamber::resetChannels(){
    for (auto iterDet = m_map_detectors.begin(); iterDet != m_map_detectors.end(); ++iterDet) {
        //(*iterDet).second->resetChannels();
        (*iterDet).second.resetChannels();
    }
    
    return;
} //End DetectorSuperchamber::resetChannels()

//shared_ptr<DetectorTiming> DetectorSuperchamber::getDetector(string & strBaseAddress){
DetectorTiming DetectorSuperchamber::getDetector(string & strBaseAddress){
    return m_map_detectors[m_map_strBaseAddr2iDetPos[strBaseAddress]];
} //End DetectorSuperchamber::getDetector()

bool DetectorSuperchamber::hasData(){
    bool bRetVal = false;
    
    for (auto iterDet = m_map_detectors.begin(); iterDet != m_map_detectors.end(); ++iterDet) {
        //bRetVal = ( bRetVal || (*iterDet).second->hasData() );
        bRetVal = ( bRetVal || (*iterDet).second.hasData() );
    }
    
    return bRetVal;
} //End DetectorSuperchamber::hasData()

bool DetectorSuperchamber::hasData(int & iNumNonZeroDet){
    bool bRetVal = false;
    
    for (auto iterDet = m_map_detectors.begin(); iterDet != m_map_detectors.end(); ++iterDet) {
        //bRetVal = ( bRetVal || (*iterDet).second->hasData() );
        bRetVal = ( bRetVal || (*iterDet).second.hasData() );
        
        if (bRetVal) {
            iNumNonZeroDet++;
        }
    }
    
    return bRetVal;
} //End DetectorSuperchamber::hasData()

//void DetectorSuperchamber::setDetector(int iDetPos, shared_ptr<DetectorTiming> inputDetector){
//void DetectorSuperchamber::setDetector(int iDetPos, DetectorTiming & inputDetector){
void DetectorSuperchamber::setDetector(int iDetPos, DetectorTiming inputDetector){
    m_map_strBaseAddr2iDetPos[inputDetector.getBaseAddress()]=iDetPos;
    
    m_map_detectors[iDetPos]=inputDetector;
    
    return;
} //End DetectorSuperchamber::setDetector()