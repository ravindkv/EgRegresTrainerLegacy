# List of Pull Requests related to Run - 3

The list of PR mentioned below, is because of the changes made in the PS energy treatment from run -2 to run -3. Earlier, in run -2, the PS energy was not used in the training, so, one need to add them after the regression evaluation. Now, in run - 3, its there for the training so if we do the same then we are adding the PS energy twice. So, need to remove the addition of PS energy after the evaluation of regression.

To keep the backward compatibility, a switch for PS energy handling was added in the CMSSW. If we training the regression with PS energy then this switch should be `true` else it should be `false`.

## Main PRs

- Added the switch for the inclusion of PS energy: [PR#37491](https://github.com/cms-sw/cmssw/pull/37491)
- **Backport PR**, [12_3_X] Added the switch for the inclusion of PS energy: [PR#37494](https://github.com/cms-sw/cmssw/pull/37494)
- ***JIRA Ticket*** (Run3 supercluster regression for EGM HLT): [https://its.cern.ch/jira/browse/CMSHLT-2293](https://its.cern.ch/jira/browse/CMSHLT-2293)

## Other related PRs

- Add PPS and EGM tags to dataRun3 GTs: [PR#37557](https://github.com/cms-sw/cmssw/pull/37557)
- [123X] Add PPS and EGM tags to dataRun3 GTs [PR#37558](https://github.com/cms-sw/cmssw/pull/37558)
- Updating EGM HLT supercluster regression tags for Run 3 in MC: [PR#37588](https://github.com/cms-sw/cmssw/pull/37588)
    - In this PR, the flag is flipped to True.
- add HLT-EGM customisation for 2018 Data: [PR#37606](https://github.com/cms-sw/cmssw/pull/37606)
    - This one is the minimal change needed to do things correctly while running on 2018 data (since source code changed to support the Run3 option).


