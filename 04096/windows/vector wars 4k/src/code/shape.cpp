#include "stableheaders.hpp"

#include "shape.hpp"

#include "gameobjects.hpp"
#include "globals.hpp"
#include "video.hpp"

//////////////////////////////////////////////////////////////////////////
// BSS
//////////////////////////////////////////////////////////////////////////
#pragma bss_seg(".bss_shape")

D3DXVECTOR2*	g_pVertex;

ShapeData		g_shapeData;

unsigned		g_shapeCommandValue;
Vector2			g_verticesUP[65536];
LPD3DXLINE		g_pD3DXLine;
float			g_shapePhase;

//////////////////////////////////////////////////////////////////////////
// DATA
//////////////////////////////////////////////////////////////////////////
#pragma data_seg(".data_shape")

// function table that maps shape commands to its according shape function
void (*g_pShapeFunctions[S_MAX])() =
{
	Shape_Forward,
	Shape_Right,
	Shape_Flip,
	Shape_Scale,
	Shape_Pen,
	Shape_Push,
	Shape_Pop,
	Shape_Flush,
	Shape_AnimRotate,
	Shape_AnimScale,
};

//////////////////////////////////////////////////////////////////////////
// CODE
//////////////////////////////////////////////////////////////////////////
#pragma code_seg(".code_shape")

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_AddVertex()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Adds a vertex at the current shape position to the vertex buffer.

*/
void Shape_AddVertex()
{
	// the matrix stack holds all information, so transform a 0/0 vertex to get the final position
	D3DXVec2TransformCoord(g_pVertex, (D3DXVECTOR2 *) &g_shapeData.g_zeroVertex, g_pMatrixStack->GetTop());

	// move to next vertex in the vertex buffer
	g_pVertex++;
	
	// we have one more vertex
	g_shapeData.g_vertices++;
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Reset()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Resets the shape by clearing the vertex buffer and raising the pen.

*/
void Shape_Reset()
{
	MemClear(&g_shapeData, sizeof(g_shapeData));
	g_pVertex = (D3DXVECTOR2*) g_verticesUP;
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Forward()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Move 0-15 steps forward along the current orientation.

*/
void Shape_Forward()
{
	g_pMatrixStack->TranslateLocal(0, -SHAPE_STEPSIZE * g_shapeCommandValue, 0);
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Right()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Turn right in 22.5� steps.

*/
void Shape_Right()
{
	g_pMatrixStack->RotateYawPitchRollLocal(0, 0, 0.125f * PI * g_shapeCommandValue);
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Flip()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Flip the x- and/or y-axis.

*/
void Shape_Flip()
{
	g_pMatrixStack->ScaleLocal(g_shapeCommandValue & 2 ? -1.0f : 1.0f, g_shapeCommandValue & 1 ? -1.0f : 1.0f, 1.0f);
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Scale()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Scale the current shape matrix in 1/8th units.

*/
void Shape_Scale()
{
	g_pMatrixStack->ScaleLocal(0.125f * g_shapeCommandValue, 0.125f * g_shapeCommandValue, 1.0f);
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Pen()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Lowers or raises the pen.

*/
void Shape_Pen()
{
	g_shapeData.g_shapePenDown = g_shapeCommandValue;
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Flush()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Flushes the shape vertex buffer by rendering everything queued up so
		far.

*/
void Shape_Flush()
{
	// anything to draw?
	if (g_shapeData.g_vertices)
		// yes! so draw user pointer primitives
		D3D_VERIFY(g_pD3DXLine->Draw((D3DXVECTOR2 *) g_verticesUP, g_shapeData.g_vertices, g_pCurrentGameObject->color), "DrawTransform() failed!");
	
	// reset the internal state
	Shape_Reset();
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Push()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Pushes the current shape matrix onto the stack.

*/
void Shape_Push()
{
	g_pMatrixStack->Push();
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_Pop()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Pops the topmost shape matrix from the stack.

*/
void Shape_Pop()
{
	g_pMatrixStack->Pop();
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_AnimRotate()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Apply a time based rotation.

*/
void Shape_AnimRotate()
{
	g_pMatrixStack->RotateYawPitchRollLocal(0, 0, g_shapePhase * 0.5f * (float) ((g_shapeCommandValue & 3) + 1));
}

////////////////////////////////////////////////////////////////////////////////
//
//	Shape_AnimScale()
//
////////////////////////////////////////////////////////////////////////////////
/**
	\brief

		Apply a time based scaling.

*/
void Shape_AnimScale()
{
	float scale = 1.0f + SinF(g_shapePhase) * 0.25f * (float) ((g_shapeCommandValue & 3) + 1);

	g_pMatrixStack->ScaleLocal(scale, scale, scale);
}
