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
#include <Standard_TypeDef.hxx>
#include <Intrv_Intervals.hxx>
#include <HLRAlgo_EdgeStatus.hxx>

void bind_HLRAlgo_EdgeStatus(py::module &mod){

py::class_<HLRAlgo_EdgeStatus, std::unique_ptr<HLRAlgo_EdgeStatus>> cls_HLRAlgo_EdgeStatus(mod, "HLRAlgo_EdgeStatus", "This class describes the Hidden Line status of an Edge. It contains :");

// Constructors
cls_HLRAlgo_EdgeStatus.def(py::init<>());
cls_HLRAlgo_EdgeStatus.def(py::init<const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal>(), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));

// Fields

// Methods
// cls_HLRAlgo_EdgeStatus.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_EdgeStatus::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_EdgeStatus::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_EdgeStatus::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_EdgeStatus::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_EdgeStatus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_EdgeStatus.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_EdgeStatus::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_EdgeStatus.def("Initialize", (void (HLRAlgo_EdgeStatus::*)(const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &HLRAlgo_EdgeStatus::Initialize, "Initialize an EdgeStatus. Default visible. The Edge is bounded by the interval <Start>, <End> with the tolerances <TolStart>, <TolEnd>.", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeStatus.def("Bounds", [](HLRAlgo_EdgeStatus &self, Standard_Real & theStart, Standard_ShortReal & theTolStart, Standard_Real & theEnd, Standard_ShortReal & theTolEnd){ self.Bounds(theStart, theTolStart, theEnd, theTolEnd); return std::tuple<Standard_Real &, Standard_Real &>(theStart, theEnd); }, "None", py::arg("theStart"), py::arg("theTolStart"), py::arg("theEnd"), py::arg("theTolEnd"));
cls_HLRAlgo_EdgeStatus.def("NbVisiblePart", (Standard_Integer (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::NbVisiblePart, "None");
cls_HLRAlgo_EdgeStatus.def("VisiblePart", [](HLRAlgo_EdgeStatus &self, const Standard_Integer Index, Standard_Real & Start, Standard_ShortReal & TolStart, Standard_Real & End, Standard_ShortReal & TolEnd){ self.VisiblePart(Index, Start, TolStart, End, TolEnd); return std::tuple<Standard_Real &, Standard_Real &>(Start, End); }, "None", py::arg("Index"), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRAlgo_EdgeStatus.def("Hide", (void (HLRAlgo_EdgeStatus::*)(const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal, const Standard_Boolean, const Standard_Boolean)) &HLRAlgo_EdgeStatus::Hide, "Hides the interval <Start>, <End> with the tolerances <TolStart>, <TolEnd>. This interval is subtracted from the visible parts. If the hidden part is on ( or under ) the face the flag <OnFace> is True ( or False ). If the hidden part is on ( or inside ) the boundary of the face the flag <OnBoundary> is True ( or False ).", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"), py::arg("OnFace"), py::arg("OnBoundary"));
cls_HLRAlgo_EdgeStatus.def("HideAll", (void (HLRAlgo_EdgeStatus::*)()) &HLRAlgo_EdgeStatus::HideAll, "Hide the whole Edge.");
cls_HLRAlgo_EdgeStatus.def("ShowAll", (void (HLRAlgo_EdgeStatus::*)()) &HLRAlgo_EdgeStatus::ShowAll, "Show the whole Edge.");
cls_HLRAlgo_EdgeStatus.def("AllHidden", (Standard_Boolean (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::AllHidden, "None");
cls_HLRAlgo_EdgeStatus.def("AllHidden", (void (HLRAlgo_EdgeStatus::*)(const Standard_Boolean)) &HLRAlgo_EdgeStatus::AllHidden, "None", py::arg("B"));
cls_HLRAlgo_EdgeStatus.def("AllVisible", (Standard_Boolean (HLRAlgo_EdgeStatus::*)() const) &HLRAlgo_EdgeStatus::AllVisible, "None");
cls_HLRAlgo_EdgeStatus.def("AllVisible", (void (HLRAlgo_EdgeStatus::*)(const Standard_Boolean)) &HLRAlgo_EdgeStatus::AllVisible, "None", py::arg("B"));

// Enums

}