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
#include <Interface_STAT.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <TColStd_HSequenceOfInteger.hxx>

void bind_Interface_STAT(py::module &mod){

py::class_<Interface_STAT> cls_Interface_STAT(mod, "Interface_STAT", "This class manages statistics to be queried asynchronously. Way of use : An operator describes a STAT form then fills it according to its progression. This produces a state of advancement of the process. This state can then be queried asynchronously : typically it is summarised as a percentage. There are also an identification of the current state, and informations on processed volume.");

// Constructors
cls_Interface_STAT.def(py::init<>());
cls_Interface_STAT.def(py::init<const Standard_CString>(), py::arg("title"));
cls_Interface_STAT.def(py::init<const Interface_STAT &>(), py::arg("other"));

// Fields

// Methods
// cls_Interface_STAT.def_static("operator new_", (void * (*)(size_t)) &Interface_STAT::operator new, "None", py::arg("theSize"));
// cls_Interface_STAT.def_static("operator delete_", (void (*)(void *)) &Interface_STAT::operator delete, "None", py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator new[]_", (void * (*)(size_t)) &Interface_STAT::operator new[], "None", py::arg("theSize"));
// cls_Interface_STAT.def_static("operator delete[]_", (void (*)(void *)) &Interface_STAT::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_STAT::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator delete_", (void (*)(void *, void *)) &Interface_STAT::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_STAT.def("Internals", [](Interface_STAT &self, opencascade::handle<TCollection_HAsciiString> & tit, Standard_Real & total, opencascade::handle<TColStd_HSequenceOfAsciiString> & phn, opencascade::handle<TColStd_HSequenceOfReal> & phw, opencascade::handle<TColStd_HSequenceOfInteger> & phdeb, opencascade::handle<TColStd_HSequenceOfInteger> & phfin, opencascade::handle<TColStd_HSequenceOfReal> & stw){ self.Internals(tit, total, phn, phw, phdeb, phfin, stw); return total; }, "Returns fields in once, without copying them, used for copy when starting", py::arg("tit"), py::arg("total"), py::arg("phn"), py::arg("phw"), py::arg("phdeb"), py::arg("phfin"), py::arg("stw"));
cls_Interface_STAT.def("AddPhase", [](Interface_STAT &self, const Standard_Real a0) -> void { return self.AddPhase(a0); });
cls_Interface_STAT.def("AddPhase", (void (Interface_STAT::*)(const Standard_Real, const Standard_CString)) &Interface_STAT::AddPhase, "Adds a new phase to the description. The first one after Create replaces the default unique one", py::arg("weight"), py::arg("name"));
cls_Interface_STAT.def("AddStep", [](Interface_STAT &self) -> void { return self.AddStep(); });
cls_Interface_STAT.def("AddStep", (void (Interface_STAT::*)(const Standard_Real)) &Interface_STAT::AddStep, "Adds a new step for the last added phase, the default unique one if no AddPhase has already been added Warning : AddStep before the first AddPhase are cancelled", py::arg("weight"));
// cls_Interface_STAT.def("Description", [](Interface_STAT &self, Standard_Integer & nbphases, Standard_Real & total, Standard_CString & title){ self.Description(nbphases, total, title); return std::tuple<Standard_Integer &, Standard_Real &, Standard_CString &>(nbphases, total, title); }, "Returns global description (cumulated weights of all phases, count of phases,1 for default, and title)", py::arg("nbphases"), py::arg("total"), py::arg("title"));
// cls_Interface_STAT.def("Phase", [](Interface_STAT &self, const Standard_Integer num, Standard_Integer & n0step, Standard_Integer & nbstep, Standard_Real & weight, Standard_CString & name){ self.Phase(num, n0step, nbstep, weight, name); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_CString &>(n0step, nbstep, weight, name); }, "Returns description of a phase, given its rank (n0 for first step, count of steps, default gives one; weight, name)", py::arg("num"), py::arg("n0step"), py::arg("nbstep"), py::arg("weight"), py::arg("name"));
cls_Interface_STAT.def("Step", (Standard_Real (Interface_STAT::*)(const Standard_Integer) const) &Interface_STAT::Step, "Returns weight of a Step, related to the cumul given for the phase. <num> is given by <n0step> + i, i between 1 and <nbsteps> (default gives n0step < 0 then weight is one)", py::arg("num"));
cls_Interface_STAT.def("Start", [](Interface_STAT &self, const Standard_Integer a0) -> void { return self.Start(a0); });
cls_Interface_STAT.def("Start", (void (Interface_STAT::*)(const Standard_Integer, const Standard_Integer) const) &Interface_STAT::Start, "Starts a STAT on its first phase (or its default one) <items> gives the total count of items, <cycles> the count of cycles If <cycles> is more than one, the first Cycle must then be started by NextCycle (NextStep/NextItem are ignored). If it is one, NextItem/NextStep can then be called", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("StartCount_", [](const Standard_Integer a0) -> void { return Interface_STAT::StartCount(a0); });
cls_Interface_STAT.def_static("StartCount_", (void (*)(const Standard_Integer, const Standard_CString)) &Interface_STAT::StartCount, "Starts a default STAT, with no phase, no step, ready to just count items. <items> gives the total count of items Hence, NextItem is available to directly count", py::arg("items"), py::arg("title"));
cls_Interface_STAT.def_static("NextPhase_", [](const Standard_Integer a0) -> void { return Interface_STAT::NextPhase(a0); });
cls_Interface_STAT.def_static("NextPhase_", (void (*)(const Standard_Integer, const Standard_Integer)) &Interface_STAT::NextPhase, "Commands to resume the preceeding phase and start a new one <items> and <cycles> as for Start, but for this new phase Ignored if count of phases is already passed If <cycles> is more than one, the first Cycle must then be started by NextCycle (NextStep/NextItem are ignored). If it is one, NextItem/NextStep can then be called", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("SetPhase_", [](const Standard_Integer a0) -> void { return Interface_STAT::SetPhase(a0); });
cls_Interface_STAT.def_static("SetPhase_", (void (*)(const Standard_Integer, const Standard_Integer)) &Interface_STAT::SetPhase, "Changes the parameters of the phase to start To be used before first counting (i.e. just after NextPhase) Can be used by an operator which has to reajust counts on run", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("NextCycle_", (void (*)(const Standard_Integer)) &Interface_STAT::NextCycle, "Commands to resume the preceeding cycle and start a new one, with a count of items Ignored if count of cycles is already passed Then, first step is started (or default one) NextItem can be called for the first step, or NextStep to pass to the next one", py::arg("items"));
cls_Interface_STAT.def_static("NextStep_", (void (*)()) &Interface_STAT::NextStep, "Commands to resume the preceeding step of the cycle Ignored if count of steps is already passed NextItem can be called for this step, NextStep passes to next");
cls_Interface_STAT.def_static("NextItem_", []() -> void { return Interface_STAT::NextItem(); });
cls_Interface_STAT.def_static("NextItem_", (void (*)(const Standard_Integer)) &Interface_STAT::NextItem, "Commands to add an item in the current step of the current cycle of the current phase By default, one item per call, can be overpassed Ignored if count of items of this cycle is already passed", py::arg("nbitems"));
cls_Interface_STAT.def_static("End_", (void (*)()) &Interface_STAT::End, "Commands to declare the process ended (hence, advancement is forced to 100 %)");
cls_Interface_STAT.def_static("Where_", []() -> Standard_CString { return Interface_STAT::Where(); });
cls_Interface_STAT.def_static("Where_", (Standard_CString (*)(const Standard_Boolean)) &Interface_STAT::Where, "Returns an identification of the STAT : <phase> True (D) : the name of the current phase <phase> False : the title of the current STAT", py::arg("phase"));
cls_Interface_STAT.def_static("Percent_", []() -> Standard_Integer { return Interface_STAT::Percent(); });
cls_Interface_STAT.def_static("Percent_", (Standard_Integer (*)(const Standard_Boolean)) &Interface_STAT::Percent, "Returns the advancement as a percentage : <phase> True : inside the current phase <phase> False (D) : relative to the whole process", py::arg("phase"));

// Enums

}