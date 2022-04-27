# EGamma Regression Trainer

This is the E/gamma Energy Regression Trainer used for RunII. It is [RegressionTrainer](https://github.com/cms-egamma/RegressionTrainer>) and [HiggsAnalysis](https://github.com/cms-egamma/HiggsAnalysis>) ported to a common build system.
It links against CMSSW but is otherwise standalone and is not built as part of CMSSW. It is very much a legacy tool and E/gamma wishes to move away from it as quickly as possible. So you have been warned.

The egamma regression training has following steps:

1. Get the input sample for the training
    1. The regression training needs two
1. Train the regression
1. Check the training output files by re-running the HLT step, if its working as expected!!!
1. Upload the `.db` file having the training information in the Global Tag (GT).


```{toctree}
---
numbered:
maxdepth: 2
caption: Contents
---

GetHLTConfig
GetReducedNtuples
Regression
GetHLTConfigForCMSSWComp
References
PR_Lists
```
