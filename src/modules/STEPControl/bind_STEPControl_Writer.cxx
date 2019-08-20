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
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_StepModel.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TopoDS_Shape.hxx>
#include <STEPControl_StepModelType.hxx>
#include <STEPControl_Writer.hxx>

void bind_STEPControl_Writer(py::module &mod){

py::class_<STEPControl_Writer, std::unique_ptr<STEPControl_Writer>> cls_STEPControl_Writer(mod, "STEPControl_Writer", "This class creates and writes STEP files from Open CASCADE models. A STEP file can be written to an existing STEP file or to a new one. Translation can be performed in one or several operations. Each translation operation outputs a distinct root entity in the STEP file.");

// Constructors
cls_STEPControl_Writer.def(py::init<>());
cls_STEPControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_STEPControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_STEPControl_Writer.def_static("operator new_", (void * (*)(size_t)) &STEPControl_Writer::operator new, "None", py::arg("theSize"));
// cls_STEPControl_Writer.def_static("operator delete_", (void (*)(void *)) &STEPControl_Writer::operator delete, "None", py::arg("theAddress"));
// cls_STEPControl_Writer.def_static("operator new[]_", (void * (*)(size_t)) &STEPControl_Writer::operator new[], "None", py::arg("theSize"));
// cls_STEPControl_Writer.def_static("operator delete[]_", (void (*)(void *)) &STEPControl_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_STEPControl_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &STEPControl_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPControl_Writer.def_static("operator delete_", (void (*)(void *, void *)) &STEPControl_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPControl_Writer.def("SetTolerance", (void (STEPControl_Writer::*)(const Standard_Real)) &STEPControl_Writer::SetTolerance, "Sets a length-measure value that will be written to uncertainty-measure-with-unit when the next shape is translated.", py::arg("Tol"));
cls_STEPControl_Writer.def("UnsetTolerance", (void (STEPControl_Writer::*)()) &STEPControl_Writer::UnsetTolerance, "Unsets the tolerance formerly forced by SetTolerance");
cls_STEPControl_Writer.def("SetWS", [](STEPControl_Writer &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.SetWS(a0); });
cls_STEPControl_Writer.def("SetWS", (void (STEPControl_Writer::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPControl_Writer::SetWS, "Sets a specific session to <me>", py::arg("WS"), py::arg("scratch"));
cls_STEPControl_Writer.def("WS", (opencascade::handle<XSControl_WorkSession> (STEPControl_Writer::*)() const) &STEPControl_Writer::WS, "Returns the session used in <me>");
cls_STEPControl_Writer.def("Model", [](STEPControl_Writer &self) -> opencascade::handle<StepData_StepModel> { return self.Model(); });
cls_STEPControl_Writer.def("Model", (opencascade::handle<StepData_StepModel> (STEPControl_Writer::*)(const Standard_Boolean)) &STEPControl_Writer::Model, "Returns the produced model. Produces a new one if not yet done or if <newone> is True This method allows for instance to edit product or header data before writing.", py::arg("newone"));
cls_STEPControl_Writer.def("Transfer", [](STEPControl_Writer &self, const TopoDS_Shape & a0, const STEPControl_StepModelType a1) -> IFSelect_ReturnStatus { return self.Transfer(a0, a1); });
cls_STEPControl_Writer.def("Transfer", (IFSelect_ReturnStatus (STEPControl_Writer::*)(const TopoDS_Shape &, const STEPControl_StepModelType, const Standard_Boolean)) &STEPControl_Writer::Transfer, "Translates shape sh to a STEP entity. mode defines the STEP entity type to be output: - STEPControlStd_AsIs translates a shape to its highest possible STEP representation. - STEPControlStd_ManifoldSolidBrep translates a shape to a STEP manifold_solid_brep or brep_with_voids entity. - STEPControlStd_FacetedBrep translates a shape into a STEP faceted_brep entity. - STEPControlStd_ShellBasedSurfaceModel translates a shape into a STEP shell_based_surface_model entity. - STEPControlStd_GeometricCurveSet translates a shape into a STEP geometric_curve_set entity.", py::arg("sh"), py::arg("mode"), py::arg("compgraph"));
cls_STEPControl_Writer.def("Write", (IFSelect_ReturnStatus (STEPControl_Writer::*)(const Standard_CString)) &STEPControl_Writer::Write, "Writes a STEP model in the file identified by filename.", py::arg("filename"));
cls_STEPControl_Writer.def("PrintStatsTransfer", [](STEPControl_Writer &self, const Standard_Integer a0) -> void { return self.PrintStatsTransfer(a0); });
cls_STEPControl_Writer.def("PrintStatsTransfer", (void (STEPControl_Writer::*)(const Standard_Integer, const Standard_Integer) const) &STEPControl_Writer::PrintStatsTransfer, "Displays the statistics for the last translation. what defines the kind of statistics that are displayed: - 0 gives general statistics (number of translated roots, number of warnings, number of fail messages), - 1 gives root results, - 2 gives statistics for all checked entities, - 3 gives the list of translated entities, - 4 gives warning and fail messages, - 5 gives fail messages only. mode is used according to the use of what. If what is 0, mode is ignored. If what is 1, 2 or 3, mode defines the following: - 0 lists the numbers of STEP entities in a STEP model, - 1 gives the number, identifier, type and result type for each STEP entity and/or its status (fail, warning, etc.), - 2 gives maximum information for each STEP entity (i.e. checks), - 3 gives the number of entities by the type of a STEP entity, - 4 gives the number of of STEP entities per result type and/or status, - 5 gives the number of pairs (STEP or result type and status), - 6 gives the number of pairs (STEP or result type and status) AND the list of entity numbers in the STEP model.", py::arg("what"), py::arg("mode"));

// Enums

}