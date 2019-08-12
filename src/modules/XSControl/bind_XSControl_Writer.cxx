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
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TopoDS_Shape.hxx>
#include <XSControl_Writer.hxx>

void bind_XSControl_Writer(py::module &mod){

py::class_<XSControl_Writer, std::unique_ptr<XSControl_Writer, Deleter<XSControl_Writer>>> cls_XSControl_Writer(mod, "XSControl_Writer", "This class gives a simple way to create then write a Model compliant to a given norm, from a Shape The model can then be edited by tools by other appropriate tools");

// Constructors
cls_XSControl_Writer.def(py::init<>());
cls_XSControl_Writer.def(py::init<const Standard_CString>(), py::arg("norm"));
cls_XSControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_XSControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_XSControl_Writer.def_static("operator new_", (void * (*)(size_t)) &XSControl_Writer::operator new, "None", py::arg("theSize"));
// cls_XSControl_Writer.def_static("operator delete_", (void (*)(void *)) &XSControl_Writer::operator delete, "None", py::arg("theAddress"));
// cls_XSControl_Writer.def_static("operator new[]_", (void * (*)(size_t)) &XSControl_Writer::operator new[], "None", py::arg("theSize"));
// cls_XSControl_Writer.def_static("operator delete[]_", (void (*)(void *)) &XSControl_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_XSControl_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &XSControl_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSControl_Writer.def_static("operator delete_", (void (*)(void *, void *)) &XSControl_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_XSControl_Writer.def("SetNorm", (Standard_Boolean (XSControl_Writer::*)(const Standard_CString)) &XSControl_Writer::SetNorm, "Sets a specific norm to <me> Returns True if done, False if <norm> is not available", py::arg("norm"));
cls_XSControl_Writer.def("SetWS", [](XSControl_Writer &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.SetWS(a0); });
cls_XSControl_Writer.def("SetWS", (void (XSControl_Writer::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &XSControl_Writer::SetWS, "Sets a specific session to <me>", py::arg("WS"), py::arg("scratch"));
cls_XSControl_Writer.def("WS", (opencascade::handle<XSControl_WorkSession> (XSControl_Writer::*)() const) &XSControl_Writer::WS, "Returns the session used in <me>");
cls_XSControl_Writer.def("Model", [](XSControl_Writer &self) -> opencascade::handle<Interface_InterfaceModel> { return self.Model(); });
cls_XSControl_Writer.def("Model", (opencascade::handle<Interface_InterfaceModel> (XSControl_Writer::*)(const Standard_Boolean)) &XSControl_Writer::Model, "Returns the produced model. Produces a new one if not yet done or if <newone> is True This method allows for instance to edit product or header data before writing", py::arg("newone"));
cls_XSControl_Writer.def("TransferShape", [](XSControl_Writer &self, const TopoDS_Shape & a0) -> IFSelect_ReturnStatus { return self.TransferShape(a0); });
cls_XSControl_Writer.def("TransferShape", (IFSelect_ReturnStatus (XSControl_Writer::*)(const TopoDS_Shape &, const Standard_Integer)) &XSControl_Writer::TransferShape, "Transfers a Shape according to the mode", py::arg("sh"), py::arg("mode"));
cls_XSControl_Writer.def("WriteFile", (IFSelect_ReturnStatus (XSControl_Writer::*)(const Standard_CString)) &XSControl_Writer::WriteFile, "Writes the produced model", py::arg("filename"));
cls_XSControl_Writer.def("PrintStatsTransfer", [](XSControl_Writer &self, const Standard_Integer a0) -> void { return self.PrintStatsTransfer(a0); });
cls_XSControl_Writer.def("PrintStatsTransfer", (void (XSControl_Writer::*)(const Standard_Integer, const Standard_Integer) const) &XSControl_Writer::PrintStatsTransfer, "Prints Statistics about Transfer", py::arg("what"), py::arg("mode"));

// Enums

}