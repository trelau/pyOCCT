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
#include <HLRBRep_Data.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <HLRAlgo_Projector.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <HLRBRep_ShapeToHLR.hxx>

void bind_HLRBRep_ShapeToHLR(py::module &mod){

py::class_<HLRBRep_ShapeToHLR, std::unique_ptr<HLRBRep_ShapeToHLR, Deleter<HLRBRep_ShapeToHLR>>> cls_HLRBRep_ShapeToHLR(mod, "HLRBRep_ShapeToHLR", "compute the OutLinedShape of a Shape with an OutLiner, a Projector and create the Data Structure of a Shape.");

// Constructors

// Fields

// Methods
// cls_HLRBRep_ShapeToHLR.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ShapeToHLR::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ShapeToHLR::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ShapeToHLR::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ShapeToHLR::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ShapeToHLR::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ShapeToHLR.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ShapeToHLR::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ShapeToHLR.def_static("Load_", [](const opencascade::handle<HLRTopoBRep_OutLiner> & a0, const HLRAlgo_Projector & a1, BRepTopAdaptor_MapOfShapeTool & a2) -> opencascade::handle<HLRBRep_Data> { return HLRBRep_ShapeToHLR::Load(a0, a1, a2); });
cls_HLRBRep_ShapeToHLR.def_static("Load_", (opencascade::handle<HLRBRep_Data> (*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const HLRAlgo_Projector &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRBRep_ShapeToHLR::Load, "Creates a DataStructure containing the OutLiner <S> depending on the projector <P> and nbIso.", py::arg("S"), py::arg("P"), py::arg("MST"), py::arg("nbIso"));

// Enums

}