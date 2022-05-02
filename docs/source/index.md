# EGamma Regression Trainer

The egamma regression training has following steps:

1. Get the input sample for the training
    1. The regression training needs two input root file. One corresponds to the `ideal Intercalibration Constants (IC)` and another for the `real IC`.
1. Train the regression and check its performance.
1. Re-validate the training by re-running the HLT step with the updated .db file.
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
Important_Talks
Default_RegressionREADME
```
