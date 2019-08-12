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
#include <IGESData_IGESModel.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Standard_OStream.hxx>
#include <IGESData_BasicEditor.hxx>
#include <IGESControl_Writer.hxx>

void bind_IGESControl_Writer(py::module &mod){

py::class_<IGESControl_Writer, std::unique_ptr<IGESControl_Writer, Deleter<IGESControl_Writer>>> cls_IGESControl_Writer(mod, "IGESControl_Writer", "This class creates and writes IGES files from CAS.CADE models. An IGES file can be written to an existing IGES file or to a new one. The translation can be performed in one or several operations. Each translation operation outputs a distinct root entity in the IGES file. To write an IGES file it is possible to use the following sequence: To modify the IGES file header or to change translation parameters it is necessary to use class Interface_Static (see IGESParameters and GeneralParameters).");

// Constructors
cls_IGESControl_Writer.def(py::init<>());
cls_IGESControl_Writer.def(py::init<const Standard_CString>(), py::arg("unit"));
cls_IGESControl_Writer.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("unit"), py::arg("modecr"));
cls_IGESControl_Writer.def(py::init<const opencascade::handle<IGESData_IGESModel> &>(), py::arg("model"));
cls_IGESControl_Writer.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const Standard_Integer>(), py::arg("model"), py::arg("modecr"));

// Fields

// Methods
// cls_IGESControl_Writer.def_static("operator new_", (void * (*)(size_t)) &IGESControl_Writer::operator new, "None", py::arg("theSize"));
// cls_IGESControl_Writer.def_static("operator delete_", (void (*)(void *)) &IGESControl_Writer::operator delete, "None", py::arg("theAddress"));
// cls_IGESControl_Writer.def_static("operator new[]_", (void * (*)(size_t)) &IGESControl_Writer::operator new[], "None", py::arg("theSize"));
// cls_IGESControl_Writer.def_static("operator delete[]_", (void (*)(void *)) &IGESControl_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_IGESControl_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &IGESControl_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESControl_Writer.def_static("operator delete_", (void (*)(void *, void *)) &IGESControl_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESControl_Writer.def("Model", (const opencascade::handle<IGESData_IGESModel> & (IGESControl_Writer::*)() const) &IGESControl_Writer::Model, "Returns the IGES model to be written in output.");
cls_IGESControl_Writer.def("TransferProcess", (const opencascade::handle<Transfer_FinderProcess> & (IGESControl_Writer::*)() const) &IGESControl_Writer::TransferProcess, "None");
cls_IGESControl_Writer.def("SetTransferProcess", (void (IGESControl_Writer::*)(const opencascade::handle<Transfer_FinderProcess> &)) &IGESControl_Writer::SetTransferProcess, "Returns/Sets the TransferProcess : it contains final results and if some, check messages", py::arg("TP"));
cls_IGESControl_Writer.def("AddShape", (Standard_Boolean (IGESControl_Writer::*)(const TopoDS_Shape &)) &IGESControl_Writer::AddShape, "Translates a Shape to IGES Entities and adds them to the model Returns True if done, False if Shape not suitable for IGES or null", py::arg("sh"));
cls_IGESControl_Writer.def("AddGeom", (Standard_Boolean (IGESControl_Writer::*)(const opencascade::handle<Standard_Transient> &)) &IGESControl_Writer::AddGeom, "Translates a Geometry (Surface or Curve) to IGES Entities and adds them to the model Returns True if done, False if geom is neither a Surface or a Curve suitable for IGES or is null", py::arg("geom"));
cls_IGESControl_Writer.def("AddEntity", (Standard_Boolean (IGESControl_Writer::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESControl_Writer::AddEntity, "Adds an IGES entity (and the ones it references) to the model", py::arg("ent"));
cls_IGESControl_Writer.def("ComputeModel", (void (IGESControl_Writer::*)()) &IGESControl_Writer::ComputeModel, "Computes the entities found in the model, which is ready to be written. This contrasts with the default computation of headers only.");
cls_IGESControl_Writer.def("Write", [](IGESControl_Writer &self, Standard_OStream & a0) -> Standard_Boolean { return self.Write(a0); });
cls_IGESControl_Writer.def("Write", (Standard_Boolean (IGESControl_Writer::*)(Standard_OStream &, const Standard_Boolean)) &IGESControl_Writer::Write, "Computes then writes the model to an OStream Returns True when done, false in case of error", py::arg("S"), py::arg("fnes"));
cls_IGESControl_Writer.def("Write", [](IGESControl_Writer &self, const Standard_CString a0) -> Standard_Boolean { return self.Write(a0); });
cls_IGESControl_Writer.def("Write", (Standard_Boolean (IGESControl_Writer::*)(const Standard_CString, const Standard_Boolean)) &IGESControl_Writer::Write, "Prepares and writes an IGES model either to an OStream, S or to a file name,CString. Returns True if the operation was performed correctly and False if an error occurred (for instance, if the processor could not create the file).", py::arg("file"), py::arg("fnes"));

// Enums

}