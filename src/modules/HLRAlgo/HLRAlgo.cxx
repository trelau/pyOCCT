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

void bind_HLRAlgo_PolyMask(py::module &);
void bind_HLRAlgo_Projector(py::module &);
void bind_HLRAlgo_EdgesBlock(py::module &);
void bind_HLRAlgo_WiresBlock(py::module &);
void bind_HLRAlgo(py::module &);
void bind_HLRAlgo_PolyHidingData(py::module &);
void bind_HLRAlgo_Array1OfPHDat(py::module &);
void bind_HLRAlgo_PolyInternalNode(py::module &);
void bind_HLRAlgo_Array1OfPINod(py::module &);
void bind_HLRAlgo_PolyInternalSegment(py::module &);
void bind_HLRAlgo_Array1OfPISeg(py::module &);
void bind_HLRAlgo_TriangleData(py::module &);
void bind_HLRAlgo_Array1OfTData(py::module &);
void bind_HLRAlgo_BiPoint(py::module &);
void bind_HLRAlgo_Coincidence(py::module &);
void bind_HLRAlgo_EdgeIterator(py::module &);
void bind_HLRAlgo_EdgeStatus(py::module &);
void bind_HLRAlgo_HArray1OfPHDat(py::module &);
void bind_HLRAlgo_HArray1OfPINod(py::module &);
void bind_HLRAlgo_HArray1OfPISeg(py::module &);
void bind_HLRAlgo_HArray1OfTData(py::module &);
void bind_HLRAlgo_Intersection(py::module &);
void bind_HLRAlgo_Interference(py::module &);
void bind_HLRAlgo_InterferenceList(py::module &);
void bind_HLRAlgo_ListIteratorOfInterferenceList(py::module &);
void bind_HLRAlgo_ListOfBPoint(py::module &);
void bind_HLRAlgo_ListIteratorOfListOfBPoint(py::module &);
void bind_HLRAlgo_PolyData(py::module &);
void bind_HLRAlgo_PolyAlgo(py::module &);
void bind_HLRAlgo_PolyInternalData(py::module &);
void bind_HLRAlgo_PolyShellData(py::module &);

PYBIND11_MODULE(HLRAlgo, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Intrv");
py::module::import("OCCT.TColgp");

bind_HLRAlgo_PolyMask(mod);
bind_HLRAlgo_Projector(mod);
bind_HLRAlgo_EdgesBlock(mod);
bind_HLRAlgo_WiresBlock(mod);
bind_HLRAlgo(mod);
bind_HLRAlgo_PolyHidingData(mod);
bind_HLRAlgo_Array1OfPHDat(mod);
bind_HLRAlgo_PolyInternalNode(mod);
bind_HLRAlgo_Array1OfPINod(mod);
bind_HLRAlgo_PolyInternalSegment(mod);
bind_HLRAlgo_Array1OfPISeg(mod);
bind_HLRAlgo_TriangleData(mod);
bind_HLRAlgo_Array1OfTData(mod);
bind_HLRAlgo_BiPoint(mod);
bind_HLRAlgo_Coincidence(mod);
bind_HLRAlgo_EdgeIterator(mod);
bind_HLRAlgo_EdgeStatus(mod);
bind_HLRAlgo_HArray1OfPHDat(mod);
bind_HLRAlgo_HArray1OfPINod(mod);
bind_HLRAlgo_HArray1OfPISeg(mod);
bind_HLRAlgo_HArray1OfTData(mod);
bind_HLRAlgo_Intersection(mod);
bind_HLRAlgo_Interference(mod);
bind_HLRAlgo_InterferenceList(mod);
bind_HLRAlgo_ListIteratorOfInterferenceList(mod);
bind_HLRAlgo_ListOfBPoint(mod);
bind_HLRAlgo_ListIteratorOfListOfBPoint(mod);
bind_HLRAlgo_PolyData(mod);
bind_HLRAlgo_PolyAlgo(mod);
bind_HLRAlgo_PolyInternalData(mod);
bind_HLRAlgo_PolyShellData(mod);

}
