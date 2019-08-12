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
#include <IFSelect_ShareOut.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Graph.hxx>
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_PacketList.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_EntityIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <IFSelect_ShareOutResult.hxx>

void bind_IFSelect_ShareOutResult(py::module &mod){

py::class_<IFSelect_ShareOutResult, std::unique_ptr<IFSelect_ShareOutResult, Deleter<IFSelect_ShareOutResult>>> cls_IFSelect_ShareOutResult(mod, "IFSelect_ShareOutResult", "This class gives results computed from a ShareOut : simulation before transfer, helps to list entities ... Transfer itself will later be performed, either by a TransferCopy to simply divide up a file, or a TransferDispatch which can be parametred with more details");

// Constructors
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_ShareOut> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("sho"), py::arg("mod"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_ShareOut> &, const Interface_Graph &>(), py::arg("sho"), py::arg("G"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_Dispatch> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("disp"), py::arg("mod"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_Dispatch> &, const Interface_Graph &>(), py::arg("disp"), py::arg("G"));

// Fields

// Methods
// cls_IFSelect_ShareOutResult.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ShareOutResult::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ShareOutResult.def_static("operator delete_", (void (*)(void *)) &IFSelect_ShareOutResult::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ShareOutResult::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ShareOutResult.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ShareOutResult::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ShareOutResult::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ShareOutResult::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ShareOutResult.def("ShareOut", (opencascade::handle<IFSelect_ShareOut> (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::ShareOut, "Returns the ShareOut used to create the ShareOutResult if creation from a Dispatch, returns a Null Handle");
cls_IFSelect_ShareOutResult.def("Graph", (const Interface_Graph & (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::Graph, "Returns the Graph used to create theShareOutResult");
cls_IFSelect_ShareOutResult.def("Reset", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Reset, "Erases computed data, in order to command a new Evaluation");
cls_IFSelect_ShareOutResult.def("Evaluate", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Evaluate, "Evaluates the result of a ShareOut : determines Entities to be forgotten by the ShareOut, Entities to be transferred several times (duplicated), prepares an iteration on the packets to be produced Called the first time anyone question is asked, or after a call to Reset. Works by calling the method Prepare.");
cls_IFSelect_ShareOutResult.def("Packets", [](IFSelect_ShareOutResult &self) -> opencascade::handle<IFSelect_PacketList> { return self.Packets(); });
cls_IFSelect_ShareOutResult.def("Packets", (opencascade::handle<IFSelect_PacketList> (IFSelect_ShareOutResult::*)(const Standard_Boolean)) &IFSelect_ShareOutResult::Packets, "Returns the list of recorded Packets, under two modes : - <complete> = False, the strict definition of Packets, i.e. for each one, the Root Entities, to be explicitely sent - <complete> = True (Default), the completely evaluated list, i.e. which really gives the destination of each entity : this mode allows to evaluate duplications Remark that to send packets, iteration remains preferable (file names are managed)", py::arg("complete"));
cls_IFSelect_ShareOutResult.def("NbPackets", (Standard_Integer (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::NbPackets, "Returns the total count of produced non empty packets (in out : calls Evaluate as necessary)");
cls_IFSelect_ShareOutResult.def("Prepare", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Prepare, "Prepares the iteration on the packets This method is called by Evaluate, but can be called anytime The iteration consists in taking each Dispatch of the ShareOut beginning by the first one, compute its packets, then iterate on these packets. Once all these packets are iterated, the iteration passes to the next Dispatch, or stops. For a creation from a unique Dispatch, same but with only this Dispatch. Each packet can be listed, or really transferred (producing a derived Model, from which a file can be generated)");
cls_IFSelect_ShareOutResult.def("More", (Standard_Boolean (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::More, "Returns True if there is more packets in the current Dispatch, else if there is more Dispatch in the ShareOut");
cls_IFSelect_ShareOutResult.def("Next", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Next, "Passes to the next Packet in the current Dispatch, or if there is none, to the next Dispatch in the ShareOut");
cls_IFSelect_ShareOutResult.def("NextDispatch", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::NextDispatch, "Passes to the next Dispatch, regardless about remaining packets");
cls_IFSelect_ShareOutResult.def("Dispatch", (opencascade::handle<IFSelect_Dispatch> (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::Dispatch, "Returns the current Dispatch");
cls_IFSelect_ShareOutResult.def("DispatchRank", (Standard_Integer (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::DispatchRank, "Returns the Rank of the current Dispatch in the ShareOut Returns Zero if there is none (iteration finished)");
cls_IFSelect_ShareOutResult.def("PacketsInDispatch", [](IFSelect_ShareOutResult &self, Standard_Integer & numpack, Standard_Integer & nbpacks){ self.PacketsInDispatch(numpack, nbpacks); return std::tuple<Standard_Integer &, Standard_Integer &>(numpack, nbpacks); }, "Returns Number (rank) of current Packet in current Dispatch, and total count of Packets in current Dispatch, as arguments", py::arg("numpack"), py::arg("nbpacks"));
cls_IFSelect_ShareOutResult.def("PacketRoot", (Interface_EntityIterator (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::PacketRoot, "Returns the list of Roots of the current Packet (never empty) (i.e. the Entities to be themselves asked for transfer) Error if there is none (iteration finished)");
cls_IFSelect_ShareOutResult.def("PacketContent", (Interface_EntityIterator (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::PacketContent, "Returns the complete content of the current Packet (i.e. with shared entities, which will also be put in the file)");
cls_IFSelect_ShareOutResult.def("FileName", (TCollection_AsciiString (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::FileName, "Returns the File Name which corresponds to current Packet (computed by ShareOut) If current Packet has no associated name (see ShareOut), the returned value is Null");

// Enums

}