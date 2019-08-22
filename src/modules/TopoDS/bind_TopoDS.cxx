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
#include <Standard.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_HShape.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_TVertex.hxx>
#include <TopoDS_TEdge.hxx>
#include <TopoDS_TWire.hxx>
#include <TopoDS_TFace.hxx>
#include <TopoDS_TShell.hxx>
#include <TopoDS_TSolid.hxx>
#include <TopoDS_TCompSolid.hxx>
#include <TopoDS_TCompound.hxx>
#include <TopoDS_Builder.hxx>
#include <TopoDS_Iterator.hxx>
#include <TopoDS.hxx>

void bind_TopoDS(py::module &mod){

py::class_<TopoDS> cls_TopoDS(mod, "TopoDS", "Provides methods to cast objects of class TopoDS_Shape to be onjects of more specialized sub-classes. Types are verified, thus in the example below, the first two blocks are correct but the third is rejected by the compiler.");

// Constructors

// Fields

// Methods
// cls_TopoDS.def_static("operator new_", (void * (*)(size_t)) &TopoDS::operator new, "None", py::arg("theSize"));
// cls_TopoDS.def_static("operator delete_", (void (*)(void *)) &TopoDS::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS::operator new[], "None", py::arg("theSize"));
// cls_TopoDS.def_static("operator delete[]_", (void (*)(void *)) &TopoDS::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS.def_static("Vertex_", (const TopoDS_Vertex & (*)(const TopoDS_Shape &)) &TopoDS::Vertex, "Basic tool to access the data structure. Casts shape S to the more specialized return type, Vertex. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Vertex_", (TopoDS_Vertex & (*)(TopoDS_Shape &)) &TopoDS::Vertex, "None", py::arg(""));
cls_TopoDS.def_static("Edge_", (const TopoDS_Edge & (*)(const TopoDS_Shape &)) &TopoDS::Edge, "Casts shape S to the more specialized return type, Edge Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Edge_", (TopoDS_Edge & (*)(TopoDS_Shape &)) &TopoDS::Edge, "None", py::arg(""));
cls_TopoDS.def_static("Wire_", (const TopoDS_Wire & (*)(const TopoDS_Shape &)) &TopoDS::Wire, "Casts shape S to the more specialized return type, Wire. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Wire_", (TopoDS_Wire & (*)(TopoDS_Shape &)) &TopoDS::Wire, "None", py::arg(""));
cls_TopoDS.def_static("Face_", (const TopoDS_Face & (*)(const TopoDS_Shape &)) &TopoDS::Face, "Casts shape S to the more specialized return type, Face. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Face_", (TopoDS_Face & (*)(TopoDS_Shape &)) &TopoDS::Face, "None", py::arg(""));
cls_TopoDS.def_static("Shell_", (const TopoDS_Shell & (*)(const TopoDS_Shape &)) &TopoDS::Shell, "Casts shape S to the more specialized return type, Shell. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Shell_", (TopoDS_Shell & (*)(TopoDS_Shape &)) &TopoDS::Shell, "None", py::arg(""));
cls_TopoDS.def_static("Solid_", (const TopoDS_Solid & (*)(const TopoDS_Shape &)) &TopoDS::Solid, "Casts shape S to the more specialized return type, Solid. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Solid_", (TopoDS_Solid & (*)(TopoDS_Shape &)) &TopoDS::Solid, "None", py::arg(""));
cls_TopoDS.def_static("CompSolid_", (const TopoDS_CompSolid & (*)(const TopoDS_Shape &)) &TopoDS::CompSolid, "Casts shape S to the more specialized return type, CompSolid. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("CompSolid_", (TopoDS_CompSolid & (*)(TopoDS_Shape &)) &TopoDS::CompSolid, "None", py::arg(""));
cls_TopoDS.def_static("Compound_", (const TopoDS_Compound & (*)(const TopoDS_Shape &)) &TopoDS::Compound, "Casts shape S to the more specialized return type, Compound. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Compound_", (TopoDS_Compound & (*)(TopoDS_Shape &)) &TopoDS::Compound, "None", py::arg(""));

// Enums

}