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
#include <Transfer_FinderProcess.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_Controller.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TopoDS_Shape.hxx>
#include <Interface_CheckIterator.hxx>
#include <XSControl_TransferWriter.hxx>
#include <Standard_Type.hxx>

void bind_XSControl_TransferWriter(py::module &mod){

py::class_<XSControl_TransferWriter, opencascade::handle<XSControl_TransferWriter>, Standard_Transient> cls_XSControl_TransferWriter(mod, "XSControl_TransferWriter", "TransferWriter gives help to control transfer to write a file after having converted data from Cascade/Imagine");

// Constructors
cls_XSControl_TransferWriter.def(py::init<>());

// Fields

// Methods
cls_XSControl_TransferWriter.def("FinderProcess", (const opencascade::handle<Transfer_FinderProcess> & (XSControl_TransferWriter::*)() const) &XSControl_TransferWriter::FinderProcess, "Returns the FinderProcess itself");
cls_XSControl_TransferWriter.def("SetFinderProcess", (void (XSControl_TransferWriter::*)(const opencascade::handle<Transfer_FinderProcess> &)) &XSControl_TransferWriter::SetFinderProcess, "Sets a new FinderProcess and forgets the former one", py::arg("theFP"));
cls_XSControl_TransferWriter.def("Controller", (const opencascade::handle<XSControl_Controller> & (XSControl_TransferWriter::*)() const) &XSControl_TransferWriter::Controller, "Returns the currently used Controller");
cls_XSControl_TransferWriter.def("SetController", (void (XSControl_TransferWriter::*)(const opencascade::handle<XSControl_Controller> &)) &XSControl_TransferWriter::SetController, "Sets a new Controller, also sets a new FinderProcess", py::arg("theCtl"));
cls_XSControl_TransferWriter.def("Clear", (void (XSControl_TransferWriter::*)(const Standard_Integer)) &XSControl_TransferWriter::Clear, "Clears recorded data according a mode 0 clears FinderProcess (results, checks) -1 create a new FinderProcess", py::arg("theMode"));
cls_XSControl_TransferWriter.def("TransferMode", (Standard_Integer (XSControl_TransferWriter::*)() const) &XSControl_TransferWriter::TransferMode, "Returns the current Transfer Mode (an Integer) It will be interpreted by the Controller to run Transfers This call form could be later replaced by more specific ones (parameters suited for each norm / transfer case)");
cls_XSControl_TransferWriter.def("SetTransferMode", (void (XSControl_TransferWriter::*)(const Standard_Integer)) &XSControl_TransferWriter::SetTransferMode, "Changes the Transfer Mode", py::arg("theMode"));
cls_XSControl_TransferWriter.def("PrintStats", [](XSControl_TransferWriter &self, const Standard_Integer a0) -> void { return self.PrintStats(a0); });
cls_XSControl_TransferWriter.def("PrintStats", (void (XSControl_TransferWriter::*)(const Standard_Integer, const Standard_Integer) const) &XSControl_TransferWriter::PrintStats, "Prints statistics on current Trace File, according what,mode See PrintStatsProcess for details", py::arg("theWhat"), py::arg("theMode"));
cls_XSControl_TransferWriter.def("RecognizeTransient", (Standard_Boolean (XSControl_TransferWriter::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_TransferWriter::RecognizeTransient, "Tells if a transient object (from an application) is a valid candidate for a transfer to a model Asks the Controller (RecognizeWriteTransient) If <obj> is a HShape, calls RecognizeShape", py::arg("theObj"));
cls_XSControl_TransferWriter.def("TransferWriteTransient", (IFSelect_ReturnStatus (XSControl_TransferWriter::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Standard_Transient> &)) &XSControl_TransferWriter::TransferWriteTransient, "Transfers a Transient object (from an application) to a model of current norm, according to the last call to SetTransferMode Works by calling the Controller Returns status : =0 if OK, >0 if error during transfer, <0 if transfer badly initialised", py::arg("theModel"), py::arg("theObj"));
cls_XSControl_TransferWriter.def("RecognizeShape", (Standard_Boolean (XSControl_TransferWriter::*)(const TopoDS_Shape &)) &XSControl_TransferWriter::RecognizeShape, "Tells if a Shape is valid for a transfer to a model Asks the Controller (RecognizeWriteShape)", py::arg("theShape"));
cls_XSControl_TransferWriter.def("TransferWriteShape", (IFSelect_ReturnStatus (XSControl_TransferWriter::*)(const opencascade::handle<Interface_InterfaceModel> &, const TopoDS_Shape &)) &XSControl_TransferWriter::TransferWriteShape, "Transfers a Shape from CasCade to a model of current norm, according to the last call to SetTransferMode Works by calling the Controller Returns status : =0 if OK, >0 if error during transfer, <0 if transfer badly initialised", py::arg("theModel"), py::arg("theShape"));
cls_XSControl_TransferWriter.def("CheckList", (Interface_CheckIterator (XSControl_TransferWriter::*)() const) &XSControl_TransferWriter::CheckList, "Returns the check-list of last transfer (write), i.e. the check-list currently recorded in the FinderProcess");
cls_XSControl_TransferWriter.def("ResultCheckList", (Interface_CheckIterator (XSControl_TransferWriter::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &XSControl_TransferWriter::ResultCheckList, "Returns the check-list of last transfer (write), but tries to bind to each check, the resulting entity in the model instead of keeping the original Mapper, whenever known", py::arg("theModel"));
cls_XSControl_TransferWriter.def_static("get_type_name_", (const char * (*)()) &XSControl_TransferWriter::get_type_name, "None");
cls_XSControl_TransferWriter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_TransferWriter::get_type_descriptor, "None");
cls_XSControl_TransferWriter.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_TransferWriter::*)() const) &XSControl_TransferWriter::DynamicType, "None");

// Enums

}