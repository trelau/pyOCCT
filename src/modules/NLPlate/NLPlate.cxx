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

void bind_NLPlate_HGPPConstraint(py::module &);
void bind_NLPlate_HPG0Constraint(py::module &);
void bind_NLPlate_HPG0G1Constraint(py::module &);
void bind_NLPlate_HPG0G2Constraint(py::module &);
void bind_NLPlate_HPG0G3Constraint(py::module &);
void bind_NLPlate_HPG1Constraint(py::module &);
void bind_NLPlate_HPG2Constraint(py::module &);
void bind_NLPlate_HPG3Constraint(py::module &);
void bind_NLPlate_StackOfPlate(py::module &);
void bind_NLPlate_ListIteratorOfStackOfPlate(py::module &);
void bind_NLPlate_SequenceOfHGPPConstraint(py::module &);
void bind_NLPlate_NLPlate(py::module &);

PYBIND11_MODULE(NLPlate, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Plate");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");

bind_NLPlate_HGPPConstraint(mod);
bind_NLPlate_HPG0Constraint(mod);
bind_NLPlate_HPG0G1Constraint(mod);
bind_NLPlate_HPG0G2Constraint(mod);
bind_NLPlate_HPG0G3Constraint(mod);
bind_NLPlate_HPG1Constraint(mod);
bind_NLPlate_HPG2Constraint(mod);
bind_NLPlate_HPG3Constraint(mod);
bind_NLPlate_StackOfPlate(mod);
bind_NLPlate_ListIteratorOfStackOfPlate(mod);
bind_NLPlate_SequenceOfHGPPConstraint(mod);
bind_NLPlate_NLPlate(mod);

}
