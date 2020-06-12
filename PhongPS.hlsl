cbuffer LightCBuf
{
	float3 lightPos;
	float3 ambient;
	float3 diffuseColor; // color of light
	float diffuseIntesity;
	float attConst;
	float attLin;
	float attQuad;
};

cbuffer ObjectCBuf
{
	float3 materialColor;
};

float4 main(float3 worldPos : Position, float3 n : Normal) : SV_TARGET
{
	// fragment to light vector data
	const float3 vToL = lightPos - worldPos;
	const float3 distToL = length(vToL);
	const float3 dirToL = vToL / distToL;
	// diffuse attentuation (distance calc)
	const float att = 1.0f / (attConst + attLin * distToL + attQuad * (distToL * distToL));
	// diffuse intensity (att * angle calc)
	const float3 diffuse = diffuseColor * diffuseIntesity * att * max(0.0f, dot(dirToL, n));
	// final color
	return float4(saturate(diffuse + ambient) * materialColor, 1.0f);

}