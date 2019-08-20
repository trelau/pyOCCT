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
#include <Standard_Handle.hxx>
#include <HLRBRep_Algo.hxx>
#include <TopoDS_Shape.hxx>
#include <HLRBRep_TypeOfResultingEdge.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_Data.hxx>
#include <HLRBRep_EdgeData.hxx>
#include <HLRBRep_HLRToShape.hxx>

void bind_HLRBRep_HLRToShape(py::module &mod){

py::class_<HLRBRep_HLRToShape, std::unique_ptr<HLRBRep_HLRToShape>> cls_HLRBRep_HLRToShape(mod, "HLRBRep_HLRToShape", "A framework for filtering the computation results of an HLRBRep_Algo algorithm by extraction. From the results calculated by the algorithm on a shape, a filter returns the type of edge you want to identify. You can choose any of the following types of output: - visible sharp edges - hidden sharp edges - visible smooth edges - hidden smooth edges - visible sewn edges - hidden sewn edges - visible outline edges - hidden outline edges. - visible isoparameters and - hidden isoparameters. Sharp edges present a C0 continuity (non G1). Smooth edges present a G1 continuity (non G2). Sewn edges present a C2 continuity. The result is composed of 2D edges in the projection plane of the view which the algorithm has worked with. These 2D edges are not included in the data structure of the visualized shape. In order to obtain a complete image, you must combine the shapes given by each of the chosen filters. The construction of the shape does not call a new computation of the algorithm, but only reads its internal results. The methods of this shape are almost identic to those of the HLRBrep_PolyHLRToShape class.");

// Constructors
cls_HLRBRep_HLRToShape.def(py::init<const opencascade::handle<HLRBRep_Algo> &>(), py::arg("A"));

// Fields

// Methods
// cls_HLRBRep_HLRToShape.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_HLRToShape::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_HLRToShape.def_static("operator delete_", (void (*)(void *)) &HLRBRep_HLRToShape::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_HLRToShape::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_HLRToShape.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_HLRToShape::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_HLRToShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_HLRToShape.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_HLRToShape::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_HLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::VCompound, "None");
cls_HLRBRep_HLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::VCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::Rg1LineVCompound, "None");
cls_HLRBRep_HLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::Rg1LineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::RgNLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::RgNLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("OutLineVCompound3d", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineVCompound3d, "None");
cls_HLRBRep_HLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::OutLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("IsoLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::IsoLineVCompound, "None");
cls_HLRBRep_HLRToShape.def("IsoLineVCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::IsoLineVCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::HCompound, "None");
cls_HLRBRep_HLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::HCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::Rg1LineHCompound, "None");
cls_HLRBRep_HLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::Rg1LineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::RgNLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::RgNLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::OutLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::OutLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("IsoLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)()) &HLRBRep_HLRToShape::IsoLineHCompound, "None");
cls_HLRBRep_HLRToShape.def("IsoLineHCompound", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_HLRToShape::IsoLineHCompound, "None", py::arg("S"));
cls_HLRBRep_HLRToShape.def("CompoundOfEdges", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_HLRToShape::CompoundOfEdges, "Returns compound of resulting edges of required type and visibility, taking into account the kind of space (2d or 3d)", py::arg("type"), py::arg("visible"), py::arg("In3d"));
cls_HLRBRep_HLRToShape.def("CompoundOfEdges", (TopoDS_Shape (HLRBRep_HLRToShape::*)(const TopoDS_Shape &, const HLRBRep_TypeOfResultingEdge, const Standard_Boolean, const Standard_Boolean)) &HLRBRep_HLRToShape::CompoundOfEdges, "For specified shape returns compound of resulting edges of required type and visibility, taking into account the kind of space (2d or 3d)", py::arg("S"), py::arg("type"), py::arg("visible"), py::arg("In3d"));

// Enums

}