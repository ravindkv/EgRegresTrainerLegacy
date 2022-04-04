# HLT Config for the CMSSW feature comparison

- Producer for writing the CMSSW feature: [SCEnergyCorrectorProducer.cc](https://cmssdt.cern.ch/lxr/source/RecoEcal/EgammaClusterProducers/src/SCEnergyCorrectorProducer.cc)
- Need to add this to the hlt config, for both barrel and endcap. The patch that we need to add in the default hlt config is:


```python
process.scEnergyCorrEB = cms.EDProducer( "SCEnergyCorrectorProducer",
    correctorCfg = process.hltParticleFlowSuperClusterECALL1Seeded.regressionConfig.clone(),
    inputSCs = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded:hltParticleFlowSuperClusterECALBarrel' ),
    writeFeatures = cms.bool(True)
)

process.scEnergyCorrEE = cms.EDProducer( "SCEnergyCorrectorProducer",
    correctorCfg = process.hltParticleFlowSuperClusterECALL1Seeded.regressionConfig.clone(),
    inputSCs = cms.InputTag( 'hltParticleFlowSuperClusterECALL1Seeded:hltParticleFlowSuperClusterECALEndcapWithPreshower' ),
    writeFeatures = cms.bool(True)
)

process.scOutput = cms.OutputModule("PoolOutputModule",
  fileName = cms.untracked.string('myTest_v3.root'),
  outputCommands = cms.untracked.vstring(
    'drop *',
    'keep edmTriggerResults_*_*_*',
    'keep triggerTriggerEvent_*_*_*',
    'keep GlobalAlgBlkBXVector_*_*_*',
    'keep GlobalExtBlkBXVector_*_*_*',
    'keep l1tEGammaBXVector_*_EGamma_*',
    'keep l1tEtSumBXVector_*_EtSum_*',
    'keep l1tJetBXVector_*_Jet_*',
    'keep l1tMuonBXVector_*_Muon_*',
    'keep l1tTauBXVector_*_Tau_*',
    'keep *_scEnergyCorr*_*_*',
    'keep *_hltEgammaHLTExtra_*_*'
  )
)
```
