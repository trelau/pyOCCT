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

void bind_STEPSelections_AssemblyLink(py::module &);
void bind_STEPSelections_SequenceOfAssemblyLink(py::module &);
void bind_STEPSelections_HSequenceOfAssemblyLink(py::module &);
void bind_STEPSelections_AssemblyComponent(py::module &);
void bind_STEPSelections_SequenceOfAssemblyComponent(py::module &);
void bind_STEPSelections_AssemblyExplorer(py::module &);
void bind_STEPSelections_Counter(py::module &);
void bind_STEPSelections_SelectAssembly(py::module &);
void bind_STEPSelections_SelectDerived(py::module &);
void bind_STEPSelections_SelectFaces(py::module &);
void bind_STEPSelections_SelectForTransfer(py::module &);
void bind_STEPSelections_SelectGSCurves(py::module &);
void bind_STEPSelections_SelectInstances(py::module &);

PYBIND11_MODULE(STEPSelections, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepGeom");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepSelect");
py::module::import("OCCT.XSControl");

bind_STEPSelections_AssemblyLink(mod);
bind_STEPSelections_SequenceOfAssemblyLink(mod);
bind_STEPSelections_HSequenceOfAssemblyLink(mod);
bind_STEPSelections_AssemblyComponent(mod);
bind_STEPSelections_SequenceOfAssemblyComponent(mod);
bind_STEPSelections_AssemblyExplorer(mod);
bind_STEPSelections_Counter(mod);
bind_STEPSelections_SelectAssembly(mod);
bind_STEPSelections_SelectDerived(mod);
bind_STEPSelections_SelectFaces(mod);
bind_STEPSelections_SelectForTransfer(mod);
bind_STEPSelections_SelectGSCurves(mod);
bind_STEPSelections_SelectInstances(mod);

}
