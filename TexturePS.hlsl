// defaults to slot 0
// Texture2D tex : register(t0) to manually register the slot
Texture2D tex;


SamplerState splr;


float4 main(float2 tc : TexCoord) : SV_TARGET
{
	return tex.Sample(splr, tc);
}