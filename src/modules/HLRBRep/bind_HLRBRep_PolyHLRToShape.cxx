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
#include <HLRBRep_PolyAlgo.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_ListOfBPnt2D.hxx>
#include <HLRBRep_PolyHLRToShape.hxx>

void bind_HLRBRep_PolyHLRToShape(py::module &mod){

py::class_<HLRBRep_PolyHLRToShape, std::unique_ptr<HLRBRep_PolyHLRToShape>> cls_HLRBRep_PolyHLRToShape(mod, "HLRBRep_PolyHLRToShape", "A framework for filtering the computation results of an HLRBRep_Algo algorithm by extraction. From the results calculated by the algorithm on a shape, a filter returns the type of edge you want to identify. You can choose any of the following types of output: - visible sharp edges - hidden sharp edges - visible smooth edges - hidden smooth edges - visible sewn edges - hidden sewn edges - visible outline edges - hidden outline edges. - visible isoparameters and - hidden isoparameters. Sharp edges present a C0 continuity (non G1). Smooth edges present a G1 continuity (non G2). Sewn edges present a C2 continuity. The result is composed of 2D edges in the projection plane of the view which the algorithm has worked with. These 2D edges are not included in the data structure of the visualized shape. In order to obtain a complete image, you must combine the shapes given by each of the chosen filters. The construction of the shape does not call a new computation of the algorithm, but only reads its internal results.");

// Constructors
cls_HLRBRep_PolyHLRToShape.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_PolyHLRToShape.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_PolyHLRToShape::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete_", (void (*)(void *)) &HLRBRep_PolyHLRToShape::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_PolyHLRToShape::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_PolyHLRToShape::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_PolyHLRToShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_PolyHLRToShape.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_PolyHLRToShape::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_PolyHLRToShape.def("Update", (void (HLRBRep_PolyHLRToShape::*)(const opencascade::handle<HLRBRep_PolyAlgo> &)) &HLRBRep_PolyHLRToShape::Update, "None", py::arg("A"));
cls_HLRBRep_PolyHLRToShape.def("Show", (void (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Show, "None");
cls_HLRBRep_PolyHLRToShape.def("Hide", (void (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Hide, "None");
cls_HLRBRep_PolyHLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::VCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("VCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::VCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Rg1LineVCompound, "Sets the extraction filter for visible smooth edges.");
cls_HLRBRep_PolyHLRToShape.def("Rg1LineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::Rg1LineVCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::RgNLineVCompound, "Sets the extraction filter for visible sewn edges.");
cls_HLRBRep_PolyHLRToShape.def("RgNLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::RgNLineVCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::OutLineVCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("OutLineVCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::OutLineVCompound, "Sets the extraction filter for visible outlines.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::HCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("HCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::HCompound, "None", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::Rg1LineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("Rg1LineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::Rg1LineHCompound, "Sets the extraction filter for hidden smooth edges.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::RgNLineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("RgNLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::RgNLineHCompound, "Sets the extraction filter for hidden sewn edges.", py::arg("S"));
cls_HLRBRep_PolyHLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)()) &HLRBRep_PolyHLRToShape::OutLineHCompound, "None");
cls_HLRBRep_PolyHLRToShape.def("OutLineHCompound", (TopoDS_Shape (HLRBRep_PolyHLRToShape::*)(const TopoDS_Shape &)) &HLRBRep_PolyHLRToShape::OutLineHCompound, "Sets the extraction filter for hidden outlines. Hidden outlines occur, for instance, in tori. In this case, the inner outlines of the torus seen on its side are hidden.", py::arg("S"));

// Enums

}