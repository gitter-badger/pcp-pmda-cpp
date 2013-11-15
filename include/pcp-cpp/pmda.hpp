/*
    Copyright 2013 Paul Colby

    This file is part of pmda-cpp.

    Pmda-cpp is free software: you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    Pmda-cpp is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
    more details.

    You should have received a copy of the GNU Lesser General Public License
    along with pmda-cpp.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __PCP_CPP_PMDA_HPP__
#define __PCP_CPP_PMDA_HPP__

#include "config.hpp"
#include "metric_description.hpp"

#include <pcp/pmapi.h>

#include <stdint.h>
#include <stdlib.h>
#include <string>

PCP_CPP_BEGIN_NAMESPACE

namespace pcp {

class pmda {

public:
    typedef int_fast16_t pmda_domain_number_type; /// @see stdpmid

    /// @brief  Virtual destructor for safe polymorphic destruction.
    virtual ~pmda() { }

    std::string get_pmda_name() const
    {
        return pmda_name;
    }

    virtual pmda_domain_number_type default_pmda_domain_number() = 0;

    pmda_domain_number_type get_pmda_domain_number() const
    {
        return pmda_domain_number;
    }

    void set_pmda_domain_number(const pmda_domain_number_type domain_number)
    {
        pmda_domain_number = domain_number;
    }

    template <class Agent>
    static int run(const int argc, char * const argv[])
    {
        try {
            Agent agent;
            /// @todo
            /// parse command line options
            /// if done, return.
            /// initialise pmda.
            /// run pmda
            return EXIT_SUCCESS;
        } catch (...) {
            return EXIT_FAILURE;
        }
    }

protected:
    /// pcp::metric_desc -> description, including cluster id, etc.
    ///// supports one or more?
    /// pcp::metric_index -> cluster, item, instance, opaque.


    virtual pcp::metrics_description get_supported_metrics() const = 0;

    virtual void begin_fetch_values() const { }

    //virtual pmAtomValue fetch_metric(const pcp::metric_id &metric) const = 0;

private:
    pmda_domain_number_type pmda_domain_number;
    std::string pmda_name;

    // parseCommandLine
    // ...?

    bool export_pmns_data(/*dir*/) const
    {
        /// @todo
        return false;
    }
};

} // pcp namespace.

PCP_CPP_END_NAMESPACE

#endif