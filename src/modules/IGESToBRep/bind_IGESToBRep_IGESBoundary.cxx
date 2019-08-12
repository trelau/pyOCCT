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
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Trsf2d.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend_WireData.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESToBRep_IGESBoundary.hxx>
#include <Standard_Type.hxx>

void bind_IGESToBRep_IGESBoundary(py::module &mod){

py::class_<IGESToBRep_IGESBoundary, opencascade::handle<IGESToBRep_IGESBoundary>, Standard_Transient> cls_IGESToBRep_IGESBoundary(mod, "IGESToBRep_IGESBoundary", "This class is intended to translate IGES boundary entity (142-CurveOnSurface, 141-Boundary or 508-Loop) into the wire. Methods Transfer are virtual and are redefined in Advanced Data Exchange to optimize the translation and take into account advanced parameters.");

// Constructors
cls_IGESToBRep_IGESBoundary.def(py::init<>());
cls_IGESToBRep_IGESBoundary.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));

// Fields

// Methods
cls_IGESToBRep_IGESBoundary.def("Init", (void (IGESToBRep_IGESBoundary::*)(const IGESToBRep_CurveAndSurface &, const opencascade::handle<IGESData_IGESEntity> &, const TopoDS_Face &, const gp_Trsf2d &, const Standard_Real, const Standard_Integer)) &IGESToBRep_IGESBoundary::Init, "Inits the object with parameters common for all types of IGES boundaries. <CS>: object to be used for retrieving translation parameters and sending messages, <entity>: boundary entity to be processed, <face>, <trans>, <uFact>: as for IGESToBRep_TopoCurve <filepreference>: preferred representation (2 or 3) given in the IGES file", py::arg("CS"), py::arg("entity"), py::arg("face"), py::arg("trans"), py::arg("uFact"), py::arg("filepreference"));
cls_IGESToBRep_IGESBoundary.def("WireData", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const) &IGESToBRep_IGESBoundary::WireData, "Returns the resulting wire");
cls_IGESToBRep_IGESBoundary.def("WireData3d", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const) &IGESToBRep_IGESBoundary::WireData3d, "Returns the wire from 3D curves (edges contain 3D curves and may contain pcurves)");
cls_IGESToBRep_IGESBoundary.def("WireData2d", (opencascade::handle<ShapeExtend_WireData> (IGESToBRep_IGESBoundary::*)() const) &IGESToBRep_IGESBoundary::WireData2d, "Returns the the wire from 2D curves (edges contain pcurves only)");
cls_IGESToBRep_IGESBoundary.def("Transfer", [](IGESToBRep_IGESBoundary &self, Standard_Boolean & okCurve, Standard_Boolean & okCurve3d, Standard_Boolean & okCurve2d, const opencascade::handle<IGESData_IGESEntity> & curve3d, const Standard_Boolean toreverse3d, const opencascade::handle<IGESData_HArray1OfIGESEntity> & curves2d, const Standard_Integer number){ Standard_Boolean rv = self.Transfer(okCurve, okCurve3d, okCurve2d, curve3d, toreverse3d, curves2d, number); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, okCurve, okCurve3d, okCurve2d); }, "Translates 141 and 142 entities. Returns True if the curve has been successfully translated, otherwise returns False. <okCurve..>: flags that indicate whether corresponding representation has been successfully translated (must be set to True before first call), <curve3d>: model space curve for 142 and current model space curve for 141, <toreverse3d>: False for 142 and current orientation flag for 141, <curves2d>: 1 parameter space curve for 142 or list of them for current model space curves for 141, <number>: 1 for 142 and rank number of model space curve for 141.", py::arg("okCurve"), py::arg("okCurve3d"), py::arg("okCurve2d"), py::arg("curve3d"), py::arg("toreverse3d"), py::arg("curves2d"), py::arg("number"));
cls_IGESToBRep_IGESBoundary.def("Transfer", [](IGESToBRep_IGESBoundary &self, Standard_Boolean & okCurve, Standard_Boolean & okCurve3d, Standard_Boolean & okCurve2d, const opencascade::handle<ShapeExtend_WireData> & curve3d, const opencascade::handle<IGESData_HArray1OfIGESEntity> & curves2d, const Standard_Boolean toreverse2d, const Standard_Integer number, opencascade::handle<ShapeExtend_WireData> & lsewd){ Standard_Boolean rv = self.Transfer(okCurve, okCurve3d, okCurve2d, curve3d, curves2d, toreverse2d, number, lsewd); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, okCurve, okCurve3d, okCurve2d); }, "Translates 508 entity. Returns True if the curve has been successfully translated, otherwise returns False. Input object IGESBoundary must be created and initialized before. <okCurve..>: flags that indicate whether corresponding representation has been successfully translated (must be set to True before first call), <curve3d>: result of translation of current edge, <curves2d>: list of parameter space curves for edge, <toreverse2d>: orientation flag of current edge in respect to its model space curve, <number>: rank number of edge, <lsewd>: returns the result of translation of current edge.", py::arg("okCurve"), py::arg("okCurve3d"), py::arg("okCurve2d"), py::arg("curve3d"), py::arg("curves2d"), py::arg("toreverse2d"), py::arg("number"), py::arg("lsewd"));
cls_IGESToBRep_IGESBoundary.def("Check", (void (IGESToBRep_IGESBoundary::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IGESToBRep_IGESBoundary::Check, "Checks result of translation of IGES boundary entities (types 141, 142 or 508). Checks consistency of 2D and 3D representations and keeps only one if they are inconsistent. <result>: result of translation (returned by Transfer), <checkclosure>: False for 142 without parent 144 entity, otherwise True, <okCurve3d>, <okCurve2d>: those returned by Transfer.", py::arg("result"), py::arg("checkclosure"), py::arg("okCurve3d"), py::arg("okCurve2d"));
cls_IGESToBRep_IGESBoundary.def_static("get_type_name_", (const char * (*)()) &IGESToBRep_IGESBoundary::get_type_name, "None");
cls_IGESToBRep_IGESBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESToBRep_IGESBoundary::get_type_descriptor, "None");
cls_IGESToBRep_IGESBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESToBRep_IGESBoundary::*)() const) &IGESToBRep_IGESBoundary::DynamicType, "None");

// Enums

}