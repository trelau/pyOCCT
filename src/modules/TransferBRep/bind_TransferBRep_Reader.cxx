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
#include <Interface_Protocol.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_CheckIterator.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <TransferBRep_Reader.hxx>

void bind_TransferBRep_Reader(py::module &mod){

py::class_<TransferBRep_Reader, std::unique_ptr<TransferBRep_Reader, Deleter<TransferBRep_Reader>>> cls_TransferBRep_Reader(mod, "TransferBRep_Reader", "This class offers a simple, easy to call, way of transferring data from interface files to Shapes from CasCade It must be specialized according to each norm/protocol, by : - defining how to read a file (specific method with protocol) - definig transfer, by providing an Actor");

// Constructors
cls_TransferBRep_Reader.def(py::init<>());

// Fields

// Methods
// cls_TransferBRep_Reader.def_static("operator new_", (void * (*)(size_t)) &TransferBRep_Reader::operator new, "None", py::arg("theSize"));
// cls_TransferBRep_Reader.def_static("operator delete_", (void (*)(void *)) &TransferBRep_Reader::operator delete, "None", py::arg("theAddress"));
// cls_TransferBRep_Reader.def_static("operator new[]_", (void * (*)(size_t)) &TransferBRep_Reader::operator new[], "None", py::arg("theSize"));
// cls_TransferBRep_Reader.def_static("operator delete[]_", (void (*)(void *)) &TransferBRep_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_TransferBRep_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &TransferBRep_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TransferBRep_Reader.def_static("operator delete_", (void (*)(void *, void *)) &TransferBRep_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_TransferBRep_Reader.def("SetProtocol", (void (TransferBRep_Reader::*)(const opencascade::handle<Interface_Protocol> &)) &TransferBRep_Reader::SetProtocol, "Records the protocol to be used for read and transfer roots", py::arg("protocol"));
cls_TransferBRep_Reader.def("Protocol", (opencascade::handle<Interface_Protocol> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::Protocol, "Returns the recorded Protocol");
cls_TransferBRep_Reader.def("SetActor", (void (TransferBRep_Reader::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &TransferBRep_Reader::SetActor, "Records the actor to be used for transfers", py::arg("actor"));
cls_TransferBRep_Reader.def("Actor", (opencascade::handle<Transfer_ActorOfTransientProcess> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::Actor, "Returns the recorded Actor");
cls_TransferBRep_Reader.def("SetFileStatus", (void (TransferBRep_Reader::*)(const Standard_Integer)) &TransferBRep_Reader::SetFileStatus, "Sets File Status to be interpreted as follows : = 0 OK < 0 file not found > 0 read error, no Model could be created", py::arg("status"));
cls_TransferBRep_Reader.def("FileStatus", (Standard_Integer (TransferBRep_Reader::*)() const) &TransferBRep_Reader::FileStatus, "Returns the File Status");
cls_TransferBRep_Reader.def("FileNotFound", (Standard_Boolean (TransferBRep_Reader::*)() const) &TransferBRep_Reader::FileNotFound, "Returns True if FileStatus is for FileNotFound");
cls_TransferBRep_Reader.def("SyntaxError", (Standard_Boolean (TransferBRep_Reader::*)() const) &TransferBRep_Reader::SyntaxError, "Returns True if FileStatus is for Error during read (major error; for local error, see CheckModel)");
cls_TransferBRep_Reader.def("SetModel", (void (TransferBRep_Reader::*)(const opencascade::handle<Interface_InterfaceModel> &)) &TransferBRep_Reader::SetModel, "Specifies a Model to work on Also clears the result and Done status", py::arg("model"));
cls_TransferBRep_Reader.def("Model", (opencascade::handle<Interface_InterfaceModel> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::Model, "Returns the Model to be worked on");
cls_TransferBRep_Reader.def("Clear", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::Clear, "clears the result and Done status. But not the Model.");
cls_TransferBRep_Reader.def("CheckStatusModel", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Boolean) const) &TransferBRep_Reader::CheckStatusModel, "Checks the Model. Returns True if there is NO FAIL at all (regardless Warnings) If <withprint> is True, also sends Checks on standard output", py::arg("withprint"));
cls_TransferBRep_Reader.def("CheckListModel", (Interface_CheckIterator (TransferBRep_Reader::*)() const) &TransferBRep_Reader::CheckListModel, "Checks the Model (complete : syntax + semantic) and returns the produced Check List");
cls_TransferBRep_Reader.def("ModeNewTransfer", (Standard_Boolean & (TransferBRep_Reader::*)()) &TransferBRep_Reader::ModeNewTransfer, "Returns (by Reference, hence can be changed) the Mode for new Transfer : True (D) means that each new Transfer produces a new TransferProcess. Else keeps the original one but each Transfer clears its (former results are not kept)");
cls_TransferBRep_Reader.def("BeginTransfer", (Standard_Boolean (TransferBRep_Reader::*)()) &TransferBRep_Reader::BeginTransfer, "Initializes the Reader for a Transfer (one,roots, or list) Also calls PrepareTransfer Returns True when done, False if could not be done");
cls_TransferBRep_Reader.def("EndTransfer", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::EndTransfer, "Ebds a Transfer (one, roots or list) by recording its result");
cls_TransferBRep_Reader.def("PrepareTransfer", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::PrepareTransfer, "Prepares the Transfer. Also can act on the Actor or change the TransientProcess if required. Should not set the Actor into the TransientProcess, it is done by caller. The provided default does nothing.");
cls_TransferBRep_Reader.def("TransferRoots", (void (TransferBRep_Reader::*)()) &TransferBRep_Reader::TransferRoots, "Transfers all Root Entities which are recognized as Geom-Topol The result will be a list of Shapes. This method calls user redefinable PrepareTransfer Remark : former result is cleared");
cls_TransferBRep_Reader.def("Transfer", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Integer)) &TransferBRep_Reader::Transfer, "Transfers an Entity given its rank in the Model (Root or not) Returns True if it is recognized as Geom-Topol. (But it can have failed : see IsDone)", py::arg("num"));
cls_TransferBRep_Reader.def("TransferList", (void (TransferBRep_Reader::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &TransferBRep_Reader::TransferList, "Transfers a list of Entities (only the ones also in the Model) Remark : former result is cleared", py::arg("list"));
cls_TransferBRep_Reader.def("IsDone", (Standard_Boolean (TransferBRep_Reader::*)() const) &TransferBRep_Reader::IsDone, "Returns True if the LAST Transfer/TransferRoots was a success");
cls_TransferBRep_Reader.def("NbShapes", (Standard_Integer (TransferBRep_Reader::*)() const) &TransferBRep_Reader::NbShapes, "Returns the count of produced Shapes (roots)");
cls_TransferBRep_Reader.def("Shapes", (opencascade::handle<TopTools_HSequenceOfShape> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::Shapes, "Returns the complete list of produced Shapes");
cls_TransferBRep_Reader.def("Shape", [](TransferBRep_Reader &self) -> const TopoDS_Shape & { return self.Shape(); });
cls_TransferBRep_Reader.def("Shape", (const TopoDS_Shape & (TransferBRep_Reader::*)(const Standard_Integer) const) &TransferBRep_Reader::Shape, "Returns a Shape given its rank, by default the first one", py::arg("num"));
cls_TransferBRep_Reader.def("ShapeResult", (TopoDS_Shape (TransferBRep_Reader::*)(const opencascade::handle<Standard_Transient> &) const) &TransferBRep_Reader::ShapeResult, "Returns a Shape produced from a given entity (if it was individually transferred or if an intermediate result is known). If no Shape is bound with <ent>, returns a Null Shape Warning : Runs on the last call to Transfer,TransferRoots,TransferList", py::arg("ent"));
cls_TransferBRep_Reader.def("OneShape", (TopoDS_Shape (TransferBRep_Reader::*)() const) &TransferBRep_Reader::OneShape, "Returns a unique Shape for the result : - a void Shape (type = SHAPE) if result is empty - a simple Shape if result has only one : returns this one - a Compound if result has more than one Shape");
cls_TransferBRep_Reader.def("NbTransients", (Standard_Integer (TransferBRep_Reader::*)() const) &TransferBRep_Reader::NbTransients, "Returns the count of produced Transient Results (roots)");
cls_TransferBRep_Reader.def("Transients", (opencascade::handle<TColStd_HSequenceOfTransient> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::Transients, "Returns the complete list of produced Transient Results");
cls_TransferBRep_Reader.def("Transient", [](TransferBRep_Reader &self) -> opencascade::handle<Standard_Transient> { return self.Transient(); });
cls_TransferBRep_Reader.def("Transient", (opencascade::handle<Standard_Transient> (TransferBRep_Reader::*)(const Standard_Integer) const) &TransferBRep_Reader::Transient, "Returns a Transient Root Result, given its rank (by default the first one)", py::arg("num"));
cls_TransferBRep_Reader.def("CheckStatusResult", (Standard_Boolean (TransferBRep_Reader::*)(const Standard_Boolean) const) &TransferBRep_Reader::CheckStatusResult, "Checks the Result of last Transfer (individual or roots, no cumulation on several transfers). Returns True if NO fail occured during Transfer (queries the TransientProcess)", py::arg("withprints"));
cls_TransferBRep_Reader.def("CheckListResult", (Interface_CheckIterator (TransferBRep_Reader::*)() const) &TransferBRep_Reader::CheckListResult, "Checks the Result of last Transfer (individual or roots, no cumulation on several transfers) and returns the produced list");
cls_TransferBRep_Reader.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (TransferBRep_Reader::*)() const) &TransferBRep_Reader::TransientProcess, "Returns the TransientProcess. It records informations about the very last transfer done. Null if no transfer yet done. Can be used for queries more accurate than the default ones.");

// Enums

}