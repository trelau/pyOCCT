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
#include <Transfer_TransientProcess.hxx>
#include <IGESToBRep_Actor.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <IGESToBRep_Reader.hxx>

void bind_IGESToBRep_Reader(py::module &mod){

py::class_<IGESToBRep_Reader, std::unique_ptr<IGESToBRep_Reader>> cls_IGESToBRep_Reader(mod, "IGESToBRep_Reader", "A simple way to read geometric IGES data. Encapsulates reading file and calling transfer tools");

// Constructors
cls_IGESToBRep_Reader.def(py::init<>());

// Fields

// Methods
// cls_IGESToBRep_Reader.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_Reader::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_Reader.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_Reader::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_Reader.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_Reader::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_Reader.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_Reader.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_Reader.def("LoadFile", (Standard_Integer (IGESToBRep_Reader::*)(const Standard_CString)) &IGESToBRep_Reader::LoadFile, "Loads a Model from a file.Returns 0 if success. returns 1 if the file could not be opened, returns -1 if an error occurred while the file was being loaded.", py::arg("filename"));
cls_IGESToBRep_Reader.def("SetModel", (void (IGESToBRep_Reader::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESToBRep_Reader::SetModel, "Specifies a Model to work on Also clears the result and Done status, sets TransientProcess", py::arg("model"));
cls_IGESToBRep_Reader.def("Model", (opencascade::handle<IGESData_IGESModel> (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::Model, "Returns the Model to be worked on.");
cls_IGESToBRep_Reader.def("SetTransientProcess", (void (IGESToBRep_Reader::*)(const opencascade::handle<Transfer_TransientProcess> &)) &IGESToBRep_Reader::SetTransientProcess, "Allows to set an already defined TransientProcess (to be called after LoadFile or SetModel)", py::arg("TP"));
cls_IGESToBRep_Reader.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::TransientProcess, "Returns the TransientProcess");
cls_IGESToBRep_Reader.def("Actor", (opencascade::handle<IGESToBRep_Actor> (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::Actor, "Returns 'theActor'");
cls_IGESToBRep_Reader.def("Clear", (void (IGESToBRep_Reader::*)()) &IGESToBRep_Reader::Clear, "Clears the results between two translation operations.");
cls_IGESToBRep_Reader.def("Check", (Standard_Boolean (IGESToBRep_Reader::*)(const Standard_Boolean) const) &IGESToBRep_Reader::Check, "Checks the IGES file that was loaded into memory. Displays error messages in the default message file if withprint is true. Returns True if no fail message was found and False if there was at least one fail message.", py::arg("withprint"));
cls_IGESToBRep_Reader.def("TransferRoots", [](IGESToBRep_Reader &self) -> void { return self.TransferRoots(); });
cls_IGESToBRep_Reader.def("TransferRoots", (void (IGESToBRep_Reader::*)(const Standard_Boolean)) &IGESToBRep_Reader::TransferRoots, "Translates root entities in an IGES file. Standard_True is the default value and means that only visible root entities are translated. Standard_False translates all of the roots (visible and invisible).", py::arg("onlyvisible"));
cls_IGESToBRep_Reader.def("Transfer", (Standard_Boolean (IGESToBRep_Reader::*)(const Standard_Integer)) &IGESToBRep_Reader::Transfer, "Transfers an Entity given its rank in the Model (Root or not) Returns True if it is recognized as Geom-Topol. (But it can have failed : see IsDone)", py::arg("num"));
cls_IGESToBRep_Reader.def("IsDone", (Standard_Boolean (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::IsDone, "Returns True if the LAST Transfer/TransferRoots was a success");
cls_IGESToBRep_Reader.def("UsedTolerance", (Standard_Real (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::UsedTolerance, "Returns the Tolerance which has been actually used, converted in millimeters (either that from File or that from Session, according the mode)");
cls_IGESToBRep_Reader.def("NbShapes", (Standard_Integer (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::NbShapes, "Returns the number of shapes produced by the translation.");
cls_IGESToBRep_Reader.def("Shape", [](IGESToBRep_Reader &self) -> TopoDS_Shape { return self.Shape(); });
cls_IGESToBRep_Reader.def("Shape", (TopoDS_Shape (IGESToBRep_Reader::*)(const Standard_Integer) const) &IGESToBRep_Reader::Shape, "Returns the num the resulting shape in a translation operation.", py::arg("num"));
cls_IGESToBRep_Reader.def("OneShape", (TopoDS_Shape (IGESToBRep_Reader::*)() const) &IGESToBRep_Reader::OneShape, "Returns all of the results in a single shape which is: - a null shape if there are no results, - a shape if there is one result, - a compound containing the resulting shapes if there are several.");

// Enums

}