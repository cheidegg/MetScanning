#ifndef RecoParticleFlow_PFPatProducer_METScan_
#define RecoParticleFlow_PFPatProducer_METScan_

// system include files
#include <memory>
#include <string>
#include <iostream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/PFParticle.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EcalDetId/interface/ESDetId.h"

#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgoRcd.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalSeverityLevelAlgo.h"

#include "DataFormats/ParticleFlowReco/interface/PFCluster.h"
#include "DataFormats/ParticleFlowReco/interface/PFClusterFwd.h"
#include "DataFormats/METReco/interface/HcalNoiseSummary.h"
#include "DataFormats/METReco/interface/CaloMET.h"
#include "DataFormats/METReco/interface/PFClusterMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/PFClusterMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"

#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"

#include "DataFormats/METReco/interface/HcalNoiseSummary.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include <math.h>

#include <TFile.h>
#include <TTree.h>
#include <TROOT.h>
#include <TVector3.h>

using namespace std;
using namespace edm;
using namespace reco;


class METScanningNtupleMaker : public edm::EDAnalyzer {
 public:

  explicit METScanningNtupleMaker(const edm::ParameterSet&);

  ~METScanningNtupleMaker();
  
  virtual void analyze(const edm::Event&, const edm::EventSetup&);

  virtual void beginRun(const edm::Run & r, const edm::EventSetup & c);

 private:
  
  edm::InputTag inputTagPfCandidates_;
  edm::InputTag inputTagPfJets_;
  edm::InputTag inputTagCaloMET_;
  edm::InputTag inputTagPFCaloMET_;
  edm::InputTag inputTagPFClusterMET_;
  edm::InputTag inputTagPFMET_;
  edm::InputTag inputTagEcalPFClusters_;
  edm::InputTag inputTagHcalPFClusters_;
  edm::InputTag inputTagHBHEPFClusters_;
  edm::InputTag inputTagHOPFClusters_;
  edm::InputTag inputTagHFPFClusters_;
  edm::InputTag inputTagTracks_;
  edm::InputTag inputTagTrackingLETMC_;
  edm::InputTag inputTagTrackingLETMS_;
  edm::InputTag inputTagTrackingMSC_;
  edm::InputTag inputTagTrackingTMSC_;
  edm::InputTag inputTagCSC_;
  edm::InputTag inputTagCSC1_;
  edm::InputTag inputTagCSC2_;
  edm::InputTag inputTagHalo_;
  edm::InputTag inputTagHBHER1_;
  edm::InputTag inputTagHBHER2L_;
  edm::InputTag inputTagHBHER2T_;
  edm::InputTag inputTagECALTP_;
  edm::InputTag inputTagECALBE_;
  edm::InputTag inputTagECALSC_;
  edm::InputTag inputTagRecHitsEB_;
  edm::InputTag inputTagRecHitsEE_;
  edm::InputTag inputTagRecHitsES_;

  size_t run,event,lumiBlock,time;
  bool filtertrackingletmc, filtertrackingletms, filtertrackingmsc, filtertrackingtmsc, filtercsc, filtercsc1, filtercsc2, filterhalo, filterhbher1, filterhbher1nozeros, filterhbher2l, filterhbher2t, filterhbheiso, filterecaltp, filterecalbe, filterecalsc; 
 
  edm::RunNumber_t irun;
  edm::EventNumber_t ievent;
  edm::LuminosityBlockNumber_t ilumiBlock;
  edm::Timestamp itime;

  std::vector<float>  pfLepton_pt;
  std::vector<float>  pfLepton_eta;
  std::vector<float>  pfLepton_phi;
  std::vector<float>  pfLepton_pdgId;

  std::vector<float>  pfJet_pt;
  std::vector<float>  pfJet_eta;
  std::vector<float>  pfJet_phi;
  std::vector<float>  pfJet_looseId;
  std::vector<float>  pfJet_tightId;
  std::vector<float>  pfJet_tlvId;
  int pfJet_hpfl;
  int pfJet_hpft;
  int pfJet_hpfv;

  float caloMETPt;
  float caloMETPhi;
  float caloMETSumEt;

  float pfCaloMETPt;
  float pfCaloMETPhi;
  float pfCaloMETSumEt;

  float pfClusterMETPt;
  float pfClusterMETPhi;
  float pfClusterMETSumEt;

  float pfMETPt;
  float pfMETPhi;
  float pfMETSumEt;

  std::vector<float>  pfClusterEcal_energy;
  std::vector<float>  pfClusterEcal_time;
  std::vector<float>  pfClusterEcal_eta;
  std::vector<float>  pfClusterEcal_phi;
  std::vector<float>  pfClusterEcal_status13;
  std::vector<float>  pfClusterEcal_status14;

  std::vector<float>  pfClusterHcal_energy;
  std::vector<float>  pfClusterHcal_time;
  std::vector<float>  pfClusterHcal_eta;
  std::vector<float>  pfClusterHcal_phi;

  std::vector<float>  pfClusterHBHE_energy;
  std::vector<float>  pfClusterHBHE_time;
  std::vector<float>  pfClusterHBHE_eta;
  std::vector<float>  pfClusterHBHE_phi;

  std::vector<float>  pfClusterHO_energy;
  std::vector<float>  pfClusterHO_time;
  std::vector<float>  pfClusterHO_eta;
  std::vector<float>  pfClusterHO_phi;

  std::vector<float>  pfClusterHF_energy;
  std::vector<float>  pfClusterHF_time;
  std::vector<float>  pfClusterHF_eta;
  std::vector<float>  pfClusterHF_phi;
  
  std::vector<float> track_pt;
  std::vector<float> track_eta;
  std::vector<float> track_phi;


  //tree stuff
  std::string outputfile_;
  TFile* tf1;
  TTree* s;

};

#endif
