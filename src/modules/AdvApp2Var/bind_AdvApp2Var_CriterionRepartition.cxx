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
#include <AdvApp2Var_CriterionRepartition.hxx>

void bind_AdvApp2Var_CriterionRepartition(py::module &mod){

py::enum_<AdvApp2Var_CriterionRepartition>(mod, "AdvApp2Var_CriterionRepartition", "way of cutting process//! all new cutting points at each step of cutting process : (a+i(b-a)/N)i at step N, (a+i(b-a)/(N+1))i at step N+1,... where (a,b) is the global interval//! add one new cutting point at each step of cutting process")
	.value("AdvApp2Var_Regular", AdvApp2Var_CriterionRepartition::AdvApp2Var_Regular)
	.value("AdvApp2Var_Incremental", AdvApp2Var_CriterionRepartition::AdvApp2Var_Incremental)
	.export_values();


}