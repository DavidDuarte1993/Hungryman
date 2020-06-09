using UnrealBuildTool;
using System.Collections.Generic;

public class PacManEditorTarget : TargetRules
{
	public PacManEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "PacMan" } );
	}
}
