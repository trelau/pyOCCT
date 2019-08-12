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
#include <ChFiDS_Spine.hxx>
#include <Standard_TypeDef.hxx>
#include <ChFiDS_ChamfMethod.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_ChamfSpine.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_ChamfSpine(py::module &mod){

py::class_<ChFiDS_ChamfSpine, opencascade::handle<ChFiDS_ChamfSpine>, ChFiDS_Spine> cls_ChFiDS_ChamfSpine(mod, "ChFiDS_ChamfSpine", "Provides data specific to chamfers distances on each of faces.");

// Constructors
cls_ChFiDS_ChamfSpine.def(py::init<>());
cls_ChFiDS_ChamfSpine.def(py::init<const Standard_Real>(), py::arg("Tol"));

// Fields

// Methods
cls_ChFiDS_ChamfSpine.def("SetDist", (void (ChFiDS_ChamfSpine::*)(const Standard_Real)) &ChFiDS_ChamfSpine::SetDist, "None", py::arg("Dis"));
cls_ChFiDS_ChamfSpine.def("GetDist", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis){ self.GetDist(Dis); return Dis; }, "None", py::arg("Dis"));
cls_ChFiDS_ChamfSpine.def("SetDists", (void (ChFiDS_ChamfSpine::*)(const Standard_Real, const Standard_Real)) &ChFiDS_ChamfSpine::SetDists, "None", py::arg("Dis1"), py::arg("Dis2"));
cls_ChFiDS_ChamfSpine.def("Dists", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis1, Standard_Real & Dis2){ self.Dists(Dis1, Dis2); return std::tuple<Standard_Real &, Standard_Real &>(Dis1, Dis2); }, "None", py::arg("Dis1"), py::arg("Dis2"));
cls_ChFiDS_ChamfSpine.def("GetDistAngle", [](ChFiDS_ChamfSpine &self, Standard_Real & Dis, Standard_Real & Angle, Standard_Boolean & DisOnF1){ self.GetDistAngle(Dis, Angle, DisOnF1); return std::tuple<Standard_Real &, Standard_Real &, Standard_Boolean &>(Dis, Angle, DisOnF1); }, "None", py::arg("Dis"), py::arg("Angle"), py::arg("DisOnF1"));
cls_ChFiDS_ChamfSpine.def("SetDistAngle", (void (ChFiDS_ChamfSpine::*)(const Standard_Real, const Standard_Real, const Standard_Boolean)) &ChFiDS_ChamfSpine::SetDistAngle, "None", py::arg("Dis"), py::arg("Angle"), py::arg("DisOnF1"));
cls_ChFiDS_ChamfSpine.def("IsChamfer", (ChFiDS_ChamfMethod (ChFiDS_ChamfSpine::*)() const) &ChFiDS_ChamfSpine::IsChamfer, "Return the method of chamfers used");
cls_ChFiDS_ChamfSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_ChamfSpine::get_type_name, "None");
cls_ChFiDS_ChamfSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_ChamfSpine::get_type_descriptor, "None");
cls_ChFiDS_ChamfSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_ChamfSpine::*)() const) &ChFiDS_ChamfSpine::DynamicType, "None");

// Enums

}