using UnrealBuildTool;
using System.Collections.Generic;

public class PacManTarget : TargetRules
{
	public PacManTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.AddRange( new string[] { "PacMan" } );
	}
}
