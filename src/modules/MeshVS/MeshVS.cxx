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

void bind_MeshVS_MeshSelectionMethod(py::module &);
void bind_MeshVS_DrawerAttribute(py::module &);
void bind_HashCode(py::module &);
void bind_MeshVS_Array1OfSequenceOfInteger(py::module &);
void bind_MeshVS_Buffer(py::module &);
void bind_MeshVS_BuilderPriority(py::module &);
void bind_MeshVS_ColorHasher(py::module &);
void bind_MeshVS_EntityType(py::module &);
void bind_MeshVS_HArray1OfSequenceOfInteger(py::module &);
void bind_MeshVS_DataSource(py::module &);
void bind_MeshVS_MeshPtr(py::module &);
void bind_MeshVS_DisplayModeFlags(py::module &);
void bind_MeshVS_PrsBuilder(py::module &);
void bind_MeshVS_SequenceOfPrsBuilder(py::module &);
void bind_MeshVS_DataMapOfIntegerOwner(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerOwner(py::module &);
void bind_MeshVS_Mesh(py::module &);
void bind_MeshVS_CommonSensitiveEntity(py::module &);
void bind_MeshVS_DataMapOfColorMapOfInteger(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfColorMapOfInteger(py::module &);
void bind_MeshVS_DataMapOfHArray1OfSequenceOfInteger(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfHArray1OfSequenceOfInteger(py::module &);
void bind_MeshVS_DataMapOfIntegerAsciiString(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerAsciiString(py::module &);
void bind_MeshVS_DataMapOfIntegerBoolean(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerBoolean(py::module &);
void bind_MeshVS_DataMapOfIntegerColor(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerColor(py::module &);
void bind_MeshVS_DataMapOfIntegerMaterial(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerMaterial(py::module &);
void bind_MeshVS_MeshEntityOwner(py::module &);
void bind_MeshVS_DataMapOfIntegerMeshEntityOwner(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerMeshEntityOwner(py::module &);
void bind_MeshVS_TwoColors(py::module &);
void bind_MeshVS_DataMapOfIntegerTwoColors(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerTwoColors(py::module &);
void bind_MeshVS_DataMapOfIntegerVector(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfIntegerVector(py::module &);
void bind_MeshVS_TwoColorsHasher(py::module &);
void bind_MeshVS_DataMapOfTwoColorsMapOfInteger(py::module &);
void bind_MeshVS_DataMapIteratorOfDataMapOfTwoColorsMapOfInteger(py::module &);
void bind_MeshVS_DataSource3D(py::module &);
void bind_MeshVS_DeformedDataSource(py::module &);
void bind_MeshVS_Drawer(py::module &);
void bind_MeshVS_DummySensitiveEntity(py::module &);
void bind_MeshVS_ElementalColorPrsBuilder(py::module &);
void bind_MeshVS_TwoNodes(py::module &);
void bind_MeshVS_TwoNodesHasher(py::module &);
void bind_MeshVS_MapOfTwoNodes(py::module &);
void bind_MeshVS_MapIteratorOfMapOfTwoNodes(py::module &);
void bind_MeshVS_MeshOwner(py::module &);
void bind_MeshVS_MeshPrsBuilder(py::module &);
void bind_MeshVS_NodalColorPrsBuilder(py::module &);
void bind_MeshVS_SelectionModeFlags(py::module &);
void bind_MeshVS_SensitiveFace(py::module &);
void bind_MeshVS_SensitiveMesh(py::module &);
void bind_MeshVS_PolyhedronVerts(py::module &);
void bind_MeshVS_PolyhedronVertsIter(py::module &);
void bind_MeshVS_SensitivePolyhedron(py::module &);
void bind_MeshVS_SensitiveQuad(py::module &);
void bind_MeshVS_SensitiveSegment(py::module &);
void bind_MeshVS_NodePair(py::module &);
void bind_MeshVS_SymmetricPairHasher(py::module &);
void bind_MeshVS_TextPrsBuilder(py::module &);
void bind_MeshVS_Tool(py::module &);
void bind_MeshVS_VectorPrsBuilder(py::module &);

PYBIND11_MODULE(MeshVS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.SelectBasics");
py::module::import("OCCT.PrsMgr");
py::module::import("OCCT.SelectMgr");
py::module::import("OCCT.AIS");
py::module::import("OCCT.Select3D");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Aspect");

bind_MeshVS_MeshSelectionMethod(mod);
bind_MeshVS_DrawerAttribute(mod);
bind_HashCode(mod);
bind_MeshVS_Array1OfSequenceOfInteger(mod);
bind_MeshVS_Buffer(mod);
bind_MeshVS_BuilderPriority(mod);
bind_MeshVS_ColorHasher(mod);
bind_MeshVS_EntityType(mod);
bind_MeshVS_HArray1OfSequenceOfInteger(mod);
bind_MeshVS_DataSource(mod);
bind_MeshVS_MeshPtr(mod);
bind_MeshVS_DisplayModeFlags(mod);
bind_MeshVS_PrsBuilder(mod);
bind_MeshVS_SequenceOfPrsBuilder(mod);
bind_MeshVS_DataMapOfIntegerOwner(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerOwner(mod);
bind_MeshVS_Mesh(mod);
bind_MeshVS_CommonSensitiveEntity(mod);
bind_MeshVS_DataMapOfColorMapOfInteger(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfColorMapOfInteger(mod);
bind_MeshVS_DataMapOfHArray1OfSequenceOfInteger(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfHArray1OfSequenceOfInteger(mod);
bind_MeshVS_DataMapOfIntegerAsciiString(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerAsciiString(mod);
bind_MeshVS_DataMapOfIntegerBoolean(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerBoolean(mod);
bind_MeshVS_DataMapOfIntegerColor(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerColor(mod);
bind_MeshVS_DataMapOfIntegerMaterial(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerMaterial(mod);
bind_MeshVS_MeshEntityOwner(mod);
bind_MeshVS_DataMapOfIntegerMeshEntityOwner(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerMeshEntityOwner(mod);
bind_MeshVS_TwoColors(mod);
bind_MeshVS_DataMapOfIntegerTwoColors(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerTwoColors(mod);
bind_MeshVS_DataMapOfIntegerVector(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfIntegerVector(mod);
bind_MeshVS_TwoColorsHasher(mod);
bind_MeshVS_DataMapOfTwoColorsMapOfInteger(mod);
bind_MeshVS_DataMapIteratorOfDataMapOfTwoColorsMapOfInteger(mod);
bind_MeshVS_DataSource3D(mod);
bind_MeshVS_DeformedDataSource(mod);
bind_MeshVS_Drawer(mod);
bind_MeshVS_DummySensitiveEntity(mod);
bind_MeshVS_ElementalColorPrsBuilder(mod);
bind_MeshVS_TwoNodes(mod);
bind_MeshVS_TwoNodesHasher(mod);
bind_MeshVS_MapOfTwoNodes(mod);
bind_MeshVS_MapIteratorOfMapOfTwoNodes(mod);
bind_MeshVS_MeshOwner(mod);
bind_MeshVS_MeshPrsBuilder(mod);
bind_MeshVS_NodalColorPrsBuilder(mod);
bind_MeshVS_SelectionModeFlags(mod);
bind_MeshVS_SensitiveFace(mod);
bind_MeshVS_SensitiveMesh(mod);
bind_MeshVS_PolyhedronVerts(mod);
bind_MeshVS_PolyhedronVertsIter(mod);
bind_MeshVS_SensitivePolyhedron(mod);
bind_MeshVS_SensitiveQuad(mod);
bind_MeshVS_SensitiveSegment(mod);
bind_MeshVS_NodePair(mod);
bind_MeshVS_SymmetricPairHasher(mod);
bind_MeshVS_TextPrsBuilder(mod);
bind_MeshVS_Tool(mod);
bind_MeshVS_VectorPrsBuilder(mod);

}
