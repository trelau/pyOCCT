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
#include <NCollection_BaseAllocator.hxx>
#include <Message_Alert.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <Message_Report.hxx>
#include <Standard_OStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <BOPAlgo_Options.hxx>

void bind_BOPAlgo_Options(py::module &mod){

py::class_<BOPAlgo_Options, std::unique_ptr<BOPAlgo_Options>> cls_BOPAlgo_Options(mod, "BOPAlgo_Options", "The class provides the following options for the algorithms in Boolean Component: - *Memory allocation tool* - tool for memory allocations; - *Error and warning reporting* - allows recording warnings and errors occurred during the operation. Error means that the algorithm has failed. - *Parallel processing mode* - provides the possibility to perform operation in parallel mode; - *Fuzzy tolerance* - additional tolerance for the operation to detect touching or coinciding cases; - *Progress indicator* - provides interface to track the progress of operation and stop the operation by user's break. - *Using the Oriented Bounding Boxes* - Allows using the Oriented Bounding Boxes of the shapes for filtering the intersections.");

// Constructors
cls_BOPAlgo_Options.def(py::init<>());
cls_BOPAlgo_Options.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));

// Fields

// Methods
// cls_BOPAlgo_Options.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_Options::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_Options.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_Options::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_Options::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_Options.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_Options::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_Options::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_Options.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_Options::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_Options.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BOPAlgo_Options::*)() const) &BOPAlgo_Options::Allocator, "Returns allocator");
cls_BOPAlgo_Options.def("Clear", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::Clear, "Clears all warnings and errors, and any data cached by the algorithm. User defined options are not cleared.");
cls_BOPAlgo_Options.def("AddError", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddError, "Adds the alert as error (fail)", py::arg("theAlert"));
cls_BOPAlgo_Options.def("AddWarning", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_Alert> &)) &BOPAlgo_Options::AddWarning, "Adds the alert as warning", py::arg("theAlert"));
cls_BOPAlgo_Options.def("HasErrors", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::HasErrors, "Returns true if algorithm has failed");
cls_BOPAlgo_Options.def("HasError", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const) &BOPAlgo_Options::HasError, "Returns true if algorithm has generated error of specified type", py::arg("theType"));
cls_BOPAlgo_Options.def("HasWarnings", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::HasWarnings, "Returns true if algorithm has generated some warning alerts");
cls_BOPAlgo_Options.def("HasWarning", (Standard_Boolean (BOPAlgo_Options::*)(const opencascade::handle<Standard_Type> &) const) &BOPAlgo_Options::HasWarning, "Returns true if algorithm has generated warning of specified type", py::arg("theType"));
cls_BOPAlgo_Options.def("GetReport", (const opencascade::handle<Message_Report> & (BOPAlgo_Options::*)() const) &BOPAlgo_Options::GetReport, "Returns report collecting all errors and warnings");
cls_BOPAlgo_Options.def("DumpErrors", (void (BOPAlgo_Options::*)(Standard_OStream &) const) &BOPAlgo_Options::DumpErrors, "Dumps the error status into the given stream", py::arg("theOS"));
cls_BOPAlgo_Options.def("DumpWarnings", (void (BOPAlgo_Options::*)(Standard_OStream &) const) &BOPAlgo_Options::DumpWarnings, "Dumps the warning statuses into the given stream", py::arg("theOS"));
cls_BOPAlgo_Options.def("ClearWarnings", (void (BOPAlgo_Options::*)()) &BOPAlgo_Options::ClearWarnings, "Clears the warnings of the algorithm");
cls_BOPAlgo_Options.def_static("GetParallelMode_", (Standard_Boolean (*)()) &BOPAlgo_Options::GetParallelMode, "Gets the global parallel mode");
cls_BOPAlgo_Options.def_static("SetParallelMode_", (void (*)(const Standard_Boolean)) &BOPAlgo_Options::SetParallelMode, "Sets the global parallel mode", py::arg("theNewMode"));
cls_BOPAlgo_Options.def("SetRunParallel", (void (BOPAlgo_Options::*)(const Standard_Boolean)) &BOPAlgo_Options::SetRunParallel, "Set the flag of parallel processing if <theFlag> is true the parallel processing is switched on if <theFlag> is false the parallel processing is switched off", py::arg("theFlag"));
cls_BOPAlgo_Options.def("RunParallel", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::RunParallel, "Returns the flag of parallel processing");
cls_BOPAlgo_Options.def("SetFuzzyValue", (void (BOPAlgo_Options::*)(const Standard_Real)) &BOPAlgo_Options::SetFuzzyValue, "Sets the additional tolerance", py::arg("theFuzz"));
cls_BOPAlgo_Options.def("FuzzyValue", (Standard_Real (BOPAlgo_Options::*)() const) &BOPAlgo_Options::FuzzyValue, "Returns the additional tolerance");
cls_BOPAlgo_Options.def("SetProgressIndicator", (void (BOPAlgo_Options::*)(const opencascade::handle<Message_ProgressIndicator> &)) &BOPAlgo_Options::SetProgressIndicator, "Set the Progress Indicator object.", py::arg("theObj"));
cls_BOPAlgo_Options.def("SetUseOBB", (void (BOPAlgo_Options::*)(const Standard_Boolean)) &BOPAlgo_Options::SetUseOBB, "Enables/Disables the usage of OBB", py::arg("theUseOBB"));
cls_BOPAlgo_Options.def("UseOBB", (Standard_Boolean (BOPAlgo_Options::*)() const) &BOPAlgo_Options::UseOBB, "Returns the flag defining usage of OBB");

// Enums

}