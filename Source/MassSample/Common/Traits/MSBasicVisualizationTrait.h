#pragma once

#include "MassEntityTraitBase.h"
#include "MassVisualizationTrait.h"

#include "MSBasicVisualizationTrait.generated.h"


UCLASS(meta=(DisplayName="Sample Visualization"))
class MASSSAMPLE_API UMSBasicVisualizationTrait : public UMassVisualizationTrait
{
	GENERATED_BODY()

public:
	UMSBasicVisualizationTrait();

protected:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;
};
