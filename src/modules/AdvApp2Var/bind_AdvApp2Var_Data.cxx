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
#include <AdvApp2Var_Data.hxx>

void bind_AdvApp2Var_Data(py::module &mod){

py::class_<AdvApp2Var_Data, std::unique_ptr<AdvApp2Var_Data, Deleter<AdvApp2Var_Data>>> cls_AdvApp2Var_Data(mod, "AdvApp2Var_Data", "/");

// Constructors

// Fields

// Methods
cls_AdvApp2Var_Data.def_static("Getmdnombr_", (mdnombr_1_ & (*)()) &AdvApp2Var_Data::Getmdnombr, "None");
cls_AdvApp2Var_Data.def_static("Getminombr_", (minombr_1_ & (*)()) &AdvApp2Var_Data::Getminombr, "None");
cls_AdvApp2Var_Data.def_static("Getmaovpar_", (maovpar_1_ & (*)()) &AdvApp2Var_Data::Getmaovpar, "None");
cls_AdvApp2Var_Data.def_static("Getmaovpch_", (maovpch_1_ & (*)()) &AdvApp2Var_Data::Getmaovpch, "None");
cls_AdvApp2Var_Data.def_static("Getmlgdrtl_", (mlgdrtl_1_ & (*)()) &AdvApp2Var_Data::Getmlgdrtl, "None");
cls_AdvApp2Var_Data.def_static("Getmmjcobi_", (mmjcobi_1_ & (*)()) &AdvApp2Var_Data::Getmmjcobi, "None");
cls_AdvApp2Var_Data.def_static("Getmmcmcnp_", (mmcmcnp_1_ & (*)()) &AdvApp2Var_Data::Getmmcmcnp, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgss_", (mmapgss_1_ & (*)()) &AdvApp2Var_Data::Getmmapgss, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs0_", (mmapgs0_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs0, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs1_", (mmapgs1_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs1, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs2_", (mmapgs2_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs2, "None");

// Enums

}