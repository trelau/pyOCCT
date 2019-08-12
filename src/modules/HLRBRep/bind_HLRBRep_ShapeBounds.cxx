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
#include <HLRTopoBRep_OutLiner.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <HLRBRep_ShapeBounds.hxx>

void bind_HLRBRep_ShapeBounds(py::module &mod){

py::class_<HLRBRep_ShapeBounds, std::unique_ptr<HLRBRep_ShapeBounds, Deleter<HLRBRep_ShapeBounds>>> cls_HLRBRep_ShapeBounds(mod, "HLRBRep_ShapeBounds", "Contains a Shape and the bounds of its vertices, edges and faces in the DataStructure.");

// Constructors
cls_HLRBRep_ShapeBounds.def(py::init<>());
cls_HLRBRep_ShapeBounds.def(py::init<const opencascade::handle<HLRTopoBRep_OutLiner> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S"), py::arg("SData"), py::arg("nbIso"), py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));
cls_HLRBRep_ShapeBounds.def(py::init<const opencascade::handle<HLRTopoBRep_OutLiner> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("S"), py::arg("nbIso"), py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));

// Fields

// Methods
// cls_HLRBRep_ShapeBounds.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ShapeBounds::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ShapeBounds::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ShapeBounds::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ShapeBounds::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ShapeBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ShapeBounds.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ShapeBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ShapeBounds.def("Translate", (void (HLRBRep_ShapeBounds::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &HLRBRep_ShapeBounds::Translate, "None", py::arg("NV"), py::arg("NE"), py::arg("NF"));
cls_HLRBRep_ShapeBounds.def("Shape", (void (HLRBRep_ShapeBounds::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &)) &HLRBRep_ShapeBounds::Shape, "None", py::arg("S"));
cls_HLRBRep_ShapeBounds.def("Shape", (const opencascade::handle<HLRTopoBRep_OutLiner> & (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::Shape, "None");
cls_HLRBRep_ShapeBounds.def("ShapeData", (void (HLRBRep_ShapeBounds::*)(const opencascade::handle<Standard_Transient> &)) &HLRBRep_ShapeBounds::ShapeData, "None", py::arg("SD"));
cls_HLRBRep_ShapeBounds.def("ShapeData", (const opencascade::handle<Standard_Transient> & (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::ShapeData, "None");
cls_HLRBRep_ShapeBounds.def("NbOfIso", (void (HLRBRep_ShapeBounds::*)(const Standard_Integer)) &HLRBRep_ShapeBounds::NbOfIso, "None", py::arg("nbIso"));
cls_HLRBRep_ShapeBounds.def("NbOfIso", (Standard_Integer (HLRBRep_ShapeBounds::*)() const) &HLRBRep_ShapeBounds::NbOfIso, "None");
cls_HLRBRep_ShapeBounds.def("Sizes", [](HLRBRep_ShapeBounds &self, Standard_Integer & NV, Standard_Integer & NE, Standard_Integer & NF){ self.Sizes(NV, NE, NF); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NV, NE, NF); }, "None", py::arg("NV"), py::arg("NE"), py::arg("NF"));
cls_HLRBRep_ShapeBounds.def("Bounds", [](HLRBRep_ShapeBounds &self, Standard_Integer & V1, Standard_Integer & V2, Standard_Integer & E1, Standard_Integer & E2, Standard_Integer & F1, Standard_Integer & F2){ self.Bounds(V1, V2, E1, E2, F1, F2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(V1, V2, E1, E2, F1, F2); }, "None", py::arg("V1"), py::arg("V2"), py::arg("E1"), py::arg("E2"), py::arg("F1"), py::arg("F2"));
cls_HLRBRep_ShapeBounds.def("UpdateMinMax", (void (HLRBRep_ShapeBounds::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRBRep_ShapeBounds::UpdateMinMax, "None", py::arg("theTotMinMax"));
cls_HLRBRep_ShapeBounds.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRBRep_ShapeBounds::*)()) &HLRBRep_ShapeBounds::MinMax, "None");

// Enums

}