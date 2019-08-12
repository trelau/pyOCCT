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
#include <IFSelect_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_Controller.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Message_Messenger.hxx>
#include <XSControl_TransferReader.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Interface_InterfaceModel.hxx>
#include <XSControl_TransferWriter.hxx>
#include <Transfer_FinderProcess.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TopoDS_Shape.hxx>
#include <Interface_CheckIterator.hxx>
#include <XSControl_Vars.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_Type.hxx>

void bind_XSControl_WorkSession(py::module &mod){

py::class_<XSControl_WorkSession, opencascade::handle<XSControl_WorkSession>, IFSelect_WorkSession> cls_XSControl_WorkSession(mod, "XSControl_WorkSession", "This WorkSession completes the basic one, by adding : - use of Controller, with norm selection... - management of transfers (both ways) with auxiliary classes TransferReader and TransferWriter -> these transfers may work with a Context List : its items are given by the user, according to the transfer to be i.e. it is interpreted by the Actors Each item is accessed by a Name");

// Constructors
cls_XSControl_WorkSession.def(py::init<>());

// Fields

// Methods
cls_XSControl_WorkSession.def("ClearData", (void (XSControl_WorkSession::*)(const Standard_Integer)) &XSControl_WorkSession::ClearData, "In addition to basic ClearData, clears Transfer and Management for interactive use, for mode = 0,1,2 and over 4 Plus : mode = 5 to clear Transfers (both ways) only mode = 6 to clear enforced results mode = 7 to clear transfers, results", py::arg("theMode"));
cls_XSControl_WorkSession.def("SelectNorm", (Standard_Boolean (XSControl_WorkSession::*)(const Standard_CString)) &XSControl_WorkSession::SelectNorm, "Selects a Norm defined by its name. A Norm is described and handled by a Controller Returns True if done, False if <normname> is unknown", py::arg("theNormName"));
cls_XSControl_WorkSession.def("SetController", (void (XSControl_WorkSession::*)(const opencascade::handle<XSControl_Controller> &)) &XSControl_WorkSession::SetController, "Selects a Norm defined by its Controller itself", py::arg("theCtl"));
cls_XSControl_WorkSession.def("SelectedNorm", [](XSControl_WorkSession &self) -> Standard_CString { return self.SelectedNorm(); });
cls_XSControl_WorkSession.def("SelectedNorm", (Standard_CString (XSControl_WorkSession::*)(const Standard_Boolean) const) &XSControl_WorkSession::SelectedNorm, "Returns the name of the last Selected Norm. If none is defined, returns an empty string By default, returns the complete name of the norm If <rsc> is True, returns the short name used for resource", py::arg("theRsc"));
cls_XSControl_WorkSession.def("NormAdaptor", (const opencascade::handle<XSControl_Controller> & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::NormAdaptor, "Returns the norm controller itself");
cls_XSControl_WorkSession.def("Context", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::Context, "Returns the current Context List, Null if not defined The Context is given to the TransientProcess for TransferRead");
cls_XSControl_WorkSession.def("SetAllContext", (void (XSControl_WorkSession::*)(const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > &)) &XSControl_WorkSession::SetAllContext, "Sets the current Context List, as a whole Sets it to the TransferReader", py::arg("theContext"));
cls_XSControl_WorkSession.def("ClearContext", (void (XSControl_WorkSession::*)()) &XSControl_WorkSession::ClearContext, "Clears the whole current Context (nullifies it)");
cls_XSControl_WorkSession.def("PrintTransferStatus", (Standard_Boolean (XSControl_WorkSession::*)(const Standard_Integer, const Standard_Boolean, const opencascade::handle<Message_Messenger> &) const) &XSControl_WorkSession::PrintTransferStatus, "Prints the transfer status of a transferred item, as beeing the Mapped n0 <num>, from MapWriter if <wri> is True, or from MapReader if <wri> is False Returns True when done, False else (i.e. num out of range)", py::arg("theNum"), py::arg("theWri"), py::arg("theS"));
cls_XSControl_WorkSession.def("InitTransferReader", (void (XSControl_WorkSession::*)(const Standard_Integer)) &XSControl_WorkSession::InitTransferReader, "Sets a Transfer Reader, by internal ways, according mode : 0 recreates it clear, 1 clears it (does not recreate) 2 aligns Roots of TransientProcess from final Results 3 aligns final Results from Roots of TransientProcess 4 begins a new transfer (by BeginTransfer) 5 recreates TransferReader then begins a new transfer", py::arg("theMode"));
cls_XSControl_WorkSession.def("SetTransferReader", (void (XSControl_WorkSession::*)(const opencascade::handle<XSControl_TransferReader> &)) &XSControl_WorkSession::SetTransferReader, "Sets a Transfer Reader, which manages transfers on reading", py::arg("theTR"));
cls_XSControl_WorkSession.def("TransferReader", (const opencascade::handle<XSControl_TransferReader> & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::TransferReader, "Returns the Transfer Reader, Null if not set");
cls_XSControl_WorkSession.def("MapReader", (opencascade::handle<Transfer_TransientProcess> (XSControl_WorkSession::*)() const) &XSControl_WorkSession::MapReader, "Returns the TransientProcess(internal data for TransferReader)");
cls_XSControl_WorkSession.def("SetMapReader", (Standard_Boolean (XSControl_WorkSession::*)(const opencascade::handle<Transfer_TransientProcess> &)) &XSControl_WorkSession::SetMapReader, "Changes the Map Reader, i.e. considers that the new one defines the relevant read results (forgets the former ones) Returns True when done, False in case of bad definition, i.e. if Model from TP differs from that of Session", py::arg("theTP"));
cls_XSControl_WorkSession.def("Result", (opencascade::handle<Standard_Transient> (XSControl_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSControl_WorkSession::Result, "Returns the result attached to a starting entity If <mode> = 0, returns Final Result If <mode> = 1, considers Last Result If <mode> = 2, considers Final, else if absent, Last returns it as Transient, if result is not transient returns the Binder <mode> = 10,11,12 idem but returns the Binder itself (if it is not, e.g. Shape, returns the Binder) <mode> = 20, returns the ResultFromModel", py::arg("theEnt"), py::arg("theMode"));
cls_XSControl_WorkSession.def("TransferReadOne", (Standard_Integer (XSControl_WorkSession::*)(const opencascade::handle<Standard_Transient> &)) &XSControl_WorkSession::TransferReadOne, "Commands the transfer of, either one entity, or a list I.E. calls the TransferReader after having analysed <ents> It is cumulated from the last BeginTransfer <ents> is processed by GiveList, hence : - <ents> a Selection : its SelectionResult - <ents> a HSequenceOfTransient : this list - <ents> the Model : in this specific case, all the roots, with no cumulation of former transfers (TransferReadRoots)", py::arg("theEnts"));
cls_XSControl_WorkSession.def("TransferReadRoots", (Standard_Integer (XSControl_WorkSession::*)()) &XSControl_WorkSession::TransferReadRoots, "Commands the transfer of all the root entities of the model i.e. calls TransferRoot from the TransferReader with the Graph No cumulation with former calls to TransferReadOne");
cls_XSControl_WorkSession.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (XSControl_WorkSession::*)()) &XSControl_WorkSession::NewModel, "produces and returns a new Model well conditionned It is produced by the Norm Controller It can be Null (if this function is not implemented)");
cls_XSControl_WorkSession.def("TransferWriter", (const opencascade::handle<XSControl_TransferWriter> & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::TransferWriter, "Returns the Transfer Reader, Null if not set");
cls_XSControl_WorkSession.def("SetMapWriter", (Standard_Boolean (XSControl_WorkSession::*)(const opencascade::handle<Transfer_FinderProcess> &)) &XSControl_WorkSession::SetMapWriter, "Changes the Map Reader, i.e. considers that the new one defines the relevant read results (forgets the former ones) Returns True when done, False if <FP> is Null", py::arg("theFP"));
cls_XSControl_WorkSession.def("TransferWriteShape", [](XSControl_WorkSession &self, const TopoDS_Shape & a0) -> IFSelect_ReturnStatus { return self.TransferWriteShape(a0); });
cls_XSControl_WorkSession.def("TransferWriteShape", (IFSelect_ReturnStatus (XSControl_WorkSession::*)(const TopoDS_Shape &, const Standard_Boolean)) &XSControl_WorkSession::TransferWriteShape, "Transfers a Shape from CasCade to a model of current norm, according to the last call to SetModeWriteShape Returns status :Done if OK, Fail if error during transfer, Error if transfer badly initialised", py::arg("theShape"), py::arg("theCompGraph"));
cls_XSControl_WorkSession.def("TransferWriteCheckList", (Interface_CheckIterator (XSControl_WorkSession::*)() const) &XSControl_WorkSession::TransferWriteCheckList, "Returns the check-list of last transfer (write) It is recorded in the FinderProcess, but it must be bound with resulting entities (in the resulting file model) rather than with original objects (in fact, their mappers)");
cls_XSControl_WorkSession.def("Vars", (const opencascade::handle<XSControl_Vars> & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::Vars, "None");
cls_XSControl_WorkSession.def("SetVars", (void (XSControl_WorkSession::*)(const opencascade::handle<XSControl_Vars> &)) &XSControl_WorkSession::SetVars, "None", py::arg("theVars"));
cls_XSControl_WorkSession.def_static("get_type_name_", (const char * (*)()) &XSControl_WorkSession::get_type_name, "None");
cls_XSControl_WorkSession.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSControl_WorkSession::get_type_descriptor, "None");
cls_XSControl_WorkSession.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSControl_WorkSession::*)() const) &XSControl_WorkSession::DynamicType, "None");

// Enums

}