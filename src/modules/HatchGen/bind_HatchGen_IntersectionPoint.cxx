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
#include <TopAbs_Orientation.hxx>
#include <TopAbs_State.hxx>
#include <HatchGen_IntersectionPoint.hxx>

void bind_HatchGen_IntersectionPoint(py::module &mod){

py::class_<HatchGen_IntersectionPoint, std::unique_ptr<HatchGen_IntersectionPoint, py::nodelete>> cls_HatchGen_IntersectionPoint(mod, "HatchGen_IntersectionPoint", "None");

// Fields

// Methods
// cls_HatchGen_IntersectionPoint.def_static("operator new_", (void * (*)(size_t)) &HatchGen_IntersectionPoint::operator new, "None", py::arg("theSize"));
// cls_HatchGen_IntersectionPoint.def_static("operator delete_", (void (*)(void *)) &HatchGen_IntersectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_HatchGen_IntersectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &HatchGen_IntersectionPoint::operator new[], "None", py::arg("theSize"));
// cls_HatchGen_IntersectionPoint.def_static("operator delete[]_", (void (*)(void *)) &HatchGen_IntersectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_HatchGen_IntersectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &HatchGen_IntersectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HatchGen_IntersectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &HatchGen_IntersectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_HatchGen_IntersectionPoint.def("SetIndex", (void (HatchGen_IntersectionPoint::*)(const Standard_Integer)) &HatchGen_IntersectionPoint::SetIndex, "Sets the index of the supporting curve.", py::arg("Index"));
cls_HatchGen_IntersectionPoint.def("Index", (Standard_Integer (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::Index, "Returns the index of the supporting curve.");
cls_HatchGen_IntersectionPoint.def("SetParameter", (void (HatchGen_IntersectionPoint::*)(const Standard_Real)) &HatchGen_IntersectionPoint::SetParameter, "Sets the parameter on the curve.", py::arg("Parameter"));
cls_HatchGen_IntersectionPoint.def("Parameter", (Standard_Real (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::Parameter, "Returns the parameter on the curve.");
cls_HatchGen_IntersectionPoint.def("SetPosition", (void (HatchGen_IntersectionPoint::*)(const TopAbs_Orientation)) &HatchGen_IntersectionPoint::SetPosition, "Sets the position of the point on the curve.", py::arg("Position"));
cls_HatchGen_IntersectionPoint.def("Position", (TopAbs_Orientation (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::Position, "Returns the position of the point on the curve.");
cls_HatchGen_IntersectionPoint.def("SetStateBefore", (void (HatchGen_IntersectionPoint::*)(const TopAbs_State)) &HatchGen_IntersectionPoint::SetStateBefore, "Sets the transition state before the intersection.", py::arg("State"));
cls_HatchGen_IntersectionPoint.def("StateBefore", (TopAbs_State (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::StateBefore, "Returns the transition state before the intersection.");
cls_HatchGen_IntersectionPoint.def("SetStateAfter", (void (HatchGen_IntersectionPoint::*)(const TopAbs_State)) &HatchGen_IntersectionPoint::SetStateAfter, "Sets the transition state after the intersection.", py::arg("State"));
cls_HatchGen_IntersectionPoint.def("StateAfter", (TopAbs_State (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::StateAfter, "Returns the transition state after of the intersection.");
cls_HatchGen_IntersectionPoint.def("SetSegmentBeginning", [](HatchGen_IntersectionPoint &self) -> void { return self.SetSegmentBeginning(); });
cls_HatchGen_IntersectionPoint.def("SetSegmentBeginning", (void (HatchGen_IntersectionPoint::*)(const Standard_Boolean)) &HatchGen_IntersectionPoint::SetSegmentBeginning, "Sets the flag that the point is the beginning of a segment.", py::arg("State"));
cls_HatchGen_IntersectionPoint.def("SegmentBeginning", (Standard_Boolean (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::SegmentBeginning, "Returns the flag that the point is the beginning of a segment.");
cls_HatchGen_IntersectionPoint.def("SetSegmentEnd", [](HatchGen_IntersectionPoint &self) -> void { return self.SetSegmentEnd(); });
cls_HatchGen_IntersectionPoint.def("SetSegmentEnd", (void (HatchGen_IntersectionPoint::*)(const Standard_Boolean)) &HatchGen_IntersectionPoint::SetSegmentEnd, "Sets the flag that the point is the end of a segment.", py::arg("State"));
cls_HatchGen_IntersectionPoint.def("SegmentEnd", (Standard_Boolean (HatchGen_IntersectionPoint::*)() const) &HatchGen_IntersectionPoint::SegmentEnd, "Returns the flag that the point is the end of a segment.");
cls_HatchGen_IntersectionPoint.def("Dump", [](HatchGen_IntersectionPoint &self) -> void { return self.Dump(); });
cls_HatchGen_IntersectionPoint.def("Dump", (void (HatchGen_IntersectionPoint::*)(const Standard_Integer) const) &HatchGen_IntersectionPoint::Dump, "Dump of the point on element.", py::arg("Index"));

// Enums

}