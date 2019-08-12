/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_Buffer.hxx>
#include <Graphic3d_TypeOfPrimitiveArray.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Graphic3d_Vec3.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_Vec4.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_OutOfRange.hxx>
#include <Graphic3d_Vec2.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <Graphic3d_BoundBuffer.hxx>

void bind_Graphic3d_ArrayOfPrimitives(py::module &mod){

py::class_<Graphic3d_ArrayOfPrimitives, opencascade::handle<Graphic3d_ArrayOfPrimitives>, Standard_Transient> cls_Graphic3d_ArrayOfPrimitives(mod, "Graphic3d_ArrayOfPrimitives", "This class furnish services to defined and fill an array of primitives which can be passed directly to graphics rendering API.");

// Constructors

// Fields

// Methods
cls_Graphic3d_ArrayOfPrimitives.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPrimitives::get_type_name, "None");
cls_Graphic3d_ArrayOfPrimitives.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPrimitives::get_type_descriptor, "None");
cls_Graphic3d_ArrayOfPrimitives.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::DynamicType, "None");
cls_Graphic3d_ArrayOfPrimitives.def("Attributes", (const opencascade::handle<Graphic3d_Buffer> & (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::Attributes, "Returns vertex attributes buffer (colors, normals, texture coordinates).");
cls_Graphic3d_ArrayOfPrimitives.def("Type", (Graphic3d_TypeOfPrimitiveArray (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::Type, "Returns the type of this primitive");
cls_Graphic3d_ArrayOfPrimitives.def("StringType", (Standard_CString (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::StringType, "Returns the string type of this primitive");
cls_Graphic3d_ArrayOfPrimitives.def("HasVertexNormals", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::HasVertexNormals, "Returns TRUE when vertex normals array is defined.");
cls_Graphic3d_ArrayOfPrimitives.def("HasVertexColors", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::HasVertexColors, "Returns TRUE when vertex colors array is defined.");
cls_Graphic3d_ArrayOfPrimitives.def("HasVertexTexels", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::HasVertexTexels, "Returns TRUE when vertex texels array is defined.");
cls_Graphic3d_ArrayOfPrimitives.def("VertexNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::VertexNumber, "Returns the number of defined vertex");
cls_Graphic3d_ArrayOfPrimitives.def("ItemNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::ItemNumber, "Returns the number of total items according to the array type.");
cls_Graphic3d_ArrayOfPrimitives.def("IsValid", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)()) &Graphic3d_ArrayOfPrimitives::IsValid, "Returns TRUE only when the contains of this array is available.");
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theVertex"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Graphic3d_Vec3 &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theVertex"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice in the array.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor32"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const Graphic3d_Vec4ub &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex color in the vertex array. Warning: theColor is ignored when the hasVColors constructor parameter is FALSE", py::arg("theVertex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex normal in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and color in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theColor is ignored when the hasVColors constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and color in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theColor is ignored when the hasVColors constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theColor32"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture in the vertex array. theTexel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theTexel"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture coordinates in the vertex array. Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice and vertex texture coordinates in the vertex array. Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const gp_Pnt &, const gp_Dir &, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: theNormal is ignored when the hasVNormals constructor parameter is FALSE and theTexel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theVertex"), py::arg("theNormal"), py::arg("theTexel"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE and Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("AddVertex", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::AddVertex, "Adds a vertice,vertex normal and texture in the vertex array. Warning: Normal is ignored when the hasVNormals constructor parameter is FALSE and Texel is ignored when the hasVTexels constructor parameter is FALSE.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertice", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Pnt &)) &Graphic3d_ArrayOfPrimitives::SetVertice, "Change the vertice of rank theIndex in the array.", py::arg("theIndex"), py::arg("theVertex"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertice", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_ArrayOfPrimitives::SetVertice, "Change the vertice of rank theIndex in the array.", py::arg("theIndex"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Graphic3d_Vec4ub &)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::SetVertexColor, "Change the vertex color of rank theIndex> in the array.", py::arg("theIndex"), py::arg("theColor32"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexNormal", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Dir &)) &Graphic3d_ArrayOfPrimitives::SetVertexNormal, "Change the vertex normal of rank theIndex in the array.", py::arg("theIndex"), py::arg("theNormal"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexNormal", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexNormal, "Change the vertex normal of rank theIndex in the array.", py::arg("theIndex"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexTexel", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const gp_Pnt2d &)) &Graphic3d_ArrayOfPrimitives::SetVertexTexel, "Change the vertex texel of rank theIndex in the array.", py::arg("theIndex"), py::arg("theTexel"));
cls_Graphic3d_ArrayOfPrimitives.def("SetVertexTexel", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetVertexTexel, "Change the vertex texel of rank theIndex in the array.", py::arg("theIndex"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("Vertice", (gp_Pnt (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::Vertice, "Returns the vertice at rank theRank from the vertex table if defined.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("Vertice", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Vertice(theRank, theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns the vertice coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", (Quantity_Color (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::VertexColor, "Returns the vertex color at rank theRank from the vertex table if defined.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, Graphic3d_Vec4ub &) const) &Graphic3d_ArrayOfPrimitives::VertexColor, "Returns the vertex color at rank theIndex from the vertex table if defined.", py::arg("theIndex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theR, Standard_Real & theG, Standard_Real & theB){ self.VertexColor(theRank, theR, theG, theB); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theR, theG, theB); }, "Returns the vertex color values at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Integer & theColor){ self.VertexColor(theRank, theColor); return theColor; }, "Returns the vertex color values at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexNormal", (gp_Dir (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::VertexNormal, "Returns the vertex normal at rank theRank from the vertex table if defined.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexNormal", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theNX, Standard_Real & theNY, Standard_Real & theNZ){ self.VertexNormal(theRank, theNX, theNY, theNZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theNX, theNY, theNZ); }, "Returns the vertex normal coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theNX"), py::arg("theNY"), py::arg("theNZ"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexTexel", (gp_Pnt2d (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::VertexTexel, "Returns the vertex texture at rank theRank from the vertex table if defined.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("VertexTexel", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theTX, Standard_Real & theTY){ self.VertexTexel(theRank, theTX, theTY); return std::tuple<Standard_Real &, Standard_Real &>(theTX, theTY); }, "Returns the vertex texture coordinates at rank theRank from the vertex table if defined.", py::arg("theRank"), py::arg("theTX"), py::arg("theTY"));
cls_Graphic3d_ArrayOfPrimitives.def("Indices", (const opencascade::handle<Graphic3d_IndexBuffer> & (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::Indices, "Returns optional index buffer.");
cls_Graphic3d_ArrayOfPrimitives.def("EdgeNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::EdgeNumber, "Returns the number of defined edges");
cls_Graphic3d_ArrayOfPrimitives.def("Edge", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::Edge, "Returns the vertex index at rank theRank in the range [1,EdgeNumber()]", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("AddEdge", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddEdge, "Adds an edge in the range [1,VertexNumber()] in the array.", py::arg("theVertexIndex"));
cls_Graphic3d_ArrayOfPrimitives.def("Bounds", (const opencascade::handle<Graphic3d_BoundBuffer> & (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::Bounds, "Returns optional bounds buffer.");
cls_Graphic3d_ArrayOfPrimitives.def("HasBoundColors", (Standard_Boolean (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::HasBoundColors, "Returns TRUE when bound colors array is defined.");
cls_Graphic3d_ArrayOfPrimitives.def("BoundNumber", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)() const) &Graphic3d_ArrayOfPrimitives::BoundNumber, "Returns the number of defined bounds");
cls_Graphic3d_ArrayOfPrimitives.def("Bound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::Bound, "Returns the edge number at rank theRank.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("BoundColor", (Quantity_Color (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer) const) &Graphic3d_ArrayOfPrimitives::BoundColor, "Returns the bound color at rank theRank from the bound table if defined.", py::arg("theRank"));
cls_Graphic3d_ArrayOfPrimitives.def("BoundColor", [](Graphic3d_ArrayOfPrimitives &self, const Standard_Integer theRank, Standard_Real & theR, Standard_Real & theG, Standard_Real & theB){ self.BoundColor(theRank, theR, theG, theB); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theR, theG, theB); }, "Returns the bound color values at rank theRank from the bound table if defined.", py::arg("theRank"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber in the bound array", py::arg("theEdgeNumber"));
cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber and bound color theBColor in the bound array. Warning: theBColor is ignored when the hasBColors constructor parameter is FALSE", py::arg("theEdgeNumber"), py::arg("theBColor"));
cls_Graphic3d_ArrayOfPrimitives.def("AddBound", (Standard_Integer (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::AddBound, "Adds a bound of length theEdgeNumber and bound color coordinates in the bound array. Warning: <theR,theG,theB> are ignored when the hasBColors constructor parameter is FALSE", py::arg("theEdgeNumber"), py::arg("theR"), py::arg("theG"), py::arg("theB"));
cls_Graphic3d_ArrayOfPrimitives.def("SetBoundColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Quantity_Color &)) &Graphic3d_ArrayOfPrimitives::SetBoundColor, "Change the bound color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theColor"));
cls_Graphic3d_ArrayOfPrimitives.def("SetBoundColor", (void (Graphic3d_ArrayOfPrimitives::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_ArrayOfPrimitives::SetBoundColor, "Change the bound color of rank theIndex in the array.", py::arg("theIndex"), py::arg("theR"), py::arg("theG"), py::arg("theB"));

// Enums

}